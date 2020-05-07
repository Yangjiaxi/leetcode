# [C++] LL(1) 递归下降表达式求值，含括号、负数

上学期开了**编译原理**这门课，今天借这道题跟大家分享一下 `LL(1)` 递归下降解析器的原理。🤔

TL;DR：想看代码的小伙伴直接往下拉就行

## 定义

先阐述（口胡）一小段定义：

`LL(k)` 分析器是一种处理某些上下文无关文法的自顶向下分析器，它从左向右读取输入，一边读取一遍构建推导树。名字中的`k`指的是在某个句型的前提下，向前看`k`个字符就可以确定现在应该使用哪一个产生式。因此 `LL(1)` 意味着对于给定的产生式集合，每次只需要向前看一个字符，就可以确定目前应该使用哪个产生式。

## 产生式

首先介绍本例中的产生式（文法），包含括号哦

```
Expr ::=
    Term + Expr
    | Term - Expr
    | Term

Term ::=
    Factor * Term
    | Factor / Term
    | Factor

Factor ::=
    (Expr)
    | NUM
    | -NUM
```

产生式主要由左部和右部列表构成，它的语义是**左部可以由某种右部构成**

```
左部 ::=
    右部Ver.1
    | 右部Ver.2
    ...
```

产生式中包括两种成分，**终结符**与**非终结符**

- 终结符为不可以继续推导下去的成分，例如数字、括号等
- 非终结符就是还没推导到位的成分，不严格地说，就是产生式的左部

对于本题来说，非终结符为`NUM`（数字）与括号的字符`(`, `)`，而`Expr`，`Term`，`Factor`均为非终结符

在非终结符中，有一个身份特殊的角色——**文法开始符号**。顾名思义，它是一切推导的**起点**。在本例中，`Expr`便是文法开始符号

## 推导

举个🌰：

对于式子`Expr: 1 - 2 * 2`，可以这样看待

```
1 - 2 * 2, Expr
1 - 2 * 2, Term - Expr
1 - 2 * 2, Factor - Expr
1 - 2 * 2, NUM - Expr
1 - 2 * 2, NUM - Term
1 - 2 * 2, NUM - Factor * Term
1 - 2 * 2, NUM - NUM * Term
1 - 2 * 2, NUM - NUM * Factor
1 - 2 * 2, NUM - NUM * NUM
```

对于每一步中所有可以进行推导的项，我们总是选择最左边的一项进行展开，这个方法叫做最左推导，同理，还有最右推导。

## FIRST集与FOLLOW集

具体的一堆理论就不讲了，简单说一下它们的定义

### FIRST集

对于一个文法符号$\alpha$（终结符或非终结符都行），从它开始推导可以得到一系列串，这些串都有首符号（终结符），而FIRST集就是这些**首符号**的集合

### FOLLOW集

对于一个非终结符A，在文法的指导下，某些句型中A的后面可能会**紧跟**着某些终结符，而这些终结符的集合便是FOLLOW集

如何从一个文法推导出这俩我就不多说了，有兴趣的小伙伴可以看看这位老哥的博客[https://www.jianshu.com/p/396c4bd0dd6b](https://www.jianshu.com/p/396c4bd0dd6b)

## 提取左公因子，消除左递归

### 消除左递归

例如对于产生式`A->Ab`，如果我一直向左边添加这个产生式就会得到

```
A->Ab->Abb->Abbb...
```

这种左递归现象是不好的，因为无法明确知道需要使用哪个产生式，因此需要消除左递归

### 左公因子提取

比如说文法`A->xB | xC`，当处理到非终结符`A`时，如果peek到了字符`x`，便无法确定使用`A->xB`还是`A->xC`，这也是不好的，因此需要进行左公因子提取

具体过程就不在这里描述了，总之消除了左递归后的产生式为：

注：其中`eps`表示空（表示停止该非终结符的推导），`->`与`::=`意义相同（好像是简写）

```
Expr -> Term Expr'
Expr'-> +Term| -Term | eps

Term -> Factor Term'
Term'-> *Factor Term' | /Factor Term' | eps

Factor -> (Expr) | NUM | -NUM
```

## ✨递归下降程序

递归下降程序其实就是把产生式翻译成了一堆小函数，从文法开始符的函数开始一直处理完所有符号，并在执行过程中进行相应操作

说明：其实我跳过了很多步，使用递归下降方法必须证明文法是满足`LL(1)`的，也就是证明同一个非终结符的产生式没有相互冲突的`FIRST`集，具体方法可以查看文末列出的一系列资料🙏

```cpp
#include <iostream>

using namespace std;

class Solution {
  private:
    char token;
    string buffer;
    int index;

    char peek() {
        // remove whitespaces
        while (buffer[index + 1] == ' ') ++index;
        return buffer[index + 1];
    }

    void consume() {
        ++index;
        token = buffer[index];
    }

    int expr() {
        // Expr -> Term Expr'
        int value = term();
        // Expr'-> +Term| -Term | eps
        while (1) {
            if (peek() == '+') {
                consume();
                value += term();
            } else if (peek() == '-') {
                consume();
                value -= term();
            } else {
                break;
            }
        }
        return value;
    }

    int term() {
        // Term -> Factor Term'
        int value = factor();
        // Term'-> *Factor Term' | /Factor Term' | eps
        while (1) {
            if (peek() == '*') {
                consume();
                value *= factor();
            } else if (peek() == '/') {
                consume();
                value /= factor();
            } else
                break;
        }
        return value;
    }

    // Factor -> (Expr) | NUM | -NUM
    int factor() {
        int sign = 1;
        if (peek() == '-') {
            consume();
            sign = -1;
        }

        int value;

        if (isdigit(peek())) {
            value = sign * number();
        } else if (peek() == '(') {
            consume(); // match (
            value = sign * expr();
            consume(); // match )
        }
        return value;
    }

    // NUM (unsigned)
    int number() {
        int value = 0;
        while (isdigit(peek())) {
            consume();
            value = value * 10 + (token - '0');
        }
        return value;
    }

  public:
    int calculate(const string &s) {
        buffer = s;
        index = -1;
        // entry
        return expr();
    }
};

int main() {
    Solution a;
    pair<string, int> test[] = {
        {"1 + -1", 0},
        {" -1 ", -1},
        {"1   + 1", 2},
        {"2 - 1 + 2", 3},
        {"(1+(4+5+2)-3)+(6+8)", 23},
        {"3+2 * 2", 7},
        {"((1 + (3 * 2 / 1) * 2) + 1) / (2 * 2 * 2 - 1)", 2}};
    for (auto &[s, t] : test) {
        cout << "`" << s << "`" << endl;
        cout << "Expected: " << t << ", Actual: " << a.calculate(s) << endl;
        cout << string(20, '-') << endl;
    }
    return 0;
}
```

## 总结

总结一下，本方法与使用栈的方法看起来相去甚远，但事实上完全一致

仔细观察非终结符函数之间的跳转，这些跳转就是栈方法中的压栈。事实上递归下降算法的运行时递归栈与传统的栈方法是同构的

此外，产生式之间的联动顺序体现的是栈方法中对优先级的限制。例如我们都知道乘除先于加减，在递归下降算法中就体现在包含加减法运算的`Expr`可以被包含乘除法运算的`Term`打破，而**打破**事实上就是优先级高的表现。同理，包含括号的`Factor`可以打破乘除运算`Term`

## 其他

递归下降程序写起来节点看起来舒服，但问题就偏偏出在递归上，因为众所周知，递归开销极大

因此人们又想出了一种不使用递归，直接进行分析的办法——**LL(1)分析表**

LL(1)分析表是一张二维的表，它表达了”当程序处于一个非终结符时，如果看到某个字符，应该采用哪个生成式“，使用分析栈与符号栈即可完成扫描，因此是一种非递归的自顶向下分析器

罗列几个博客供感兴趣的小伙伴参考：

- [[简书] 编译原理-求文法G的预测分析表](https://www.jianshu.com/p/feb295459835)
- [[知乎] 语法分析 | LL(1) 分析算法](https://zhuanlan.zhihu.com/p/31301086)
- [[博客园] 《编译原理》构造 LL(1) 分析表的步骤 - 例题解析](https://www.cnblogs.com/xpwi/p/11065006.html)
