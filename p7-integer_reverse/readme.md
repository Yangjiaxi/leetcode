# 07 整数反转

输入数字(int32)，输出逆序

若结果超出int32范围，则返回0

e.g.

```js
       convert(123) -> 321
      convert(-123) -> -321
convert(2147483647) -> 0
```

---

从尾部开始逐步分离

```js
res <- 0

loop {
    p   <- num mod 10
    num <- num / 10
    if this operation will not overflow: // KEY_CODE
        res <- res * 10 + p
    else return 0
} until num == 0

return res
```

其中`res <- res * 10 + num mod 10`是唯一具有溢出风险的代码

如何判断是否会造成溢出？

用正数举例

```js
p <- num mod 10

IF  res * 10 + p >= INT_MAX
=>  res >= (INT_MAX - p) / 10

1. res == 214748364 (=INT_MAX / 10)  
    => 此时p只要大于7就会溢出，因为这之后res将大于2147483647

2. res  > 214748364 (>INT_MAX / 10)
    => 无论p取什么值，这之后res都会溢出
```

负数同理
