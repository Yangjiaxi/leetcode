# 01 两数之和

给定一个整数数组`nums`和一个目标值`target`，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定`nums=[2,7,11,15],target=9`

因为`nums[0]+nums[1]=2+7=9`
所以返回`[0,1]`

---

只存在一种`a+b=target`

遍历数组，如果`target-element`不在`map`中，就存储`element`，如果存在就返回`[IDX(target-element), IDX(element)]`

这里反过来输出是因为`target-element`出现在`element`前面
