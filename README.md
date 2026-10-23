# Embedded Linux Learning

嵌入式 Linux 软件开发学习记录

## Contents

- c

# c/aaray

## 学习内容
- 一维整形数组
- 二维整形数组
- 一维字符数组
- 二维字符数组
- 字符串

## 练习
- matrix_transpose.c
- two_dimension1.c
- yanghui_triangle.c

## 易错点
- 字符串以空字符/0结尾
- 数组是连续储存的，数组名代表数组的首地址,二维数组优先行序存储.
- sizeof(数组名)=整个数组占用的空间
- 数组中元素个数=sizeof(数组名) / sizeof(数据类型)
- 二维数组行数 = sizeof(数组名) / sizeof（行名a[0]）
- 二位数组列数 = sizeof(行名) / sizeof(数据类型)

# c/pointer

## 学习内容
- 指针声明与指针解引用

## 练习
- pinter_basic.c

## 易错点
- 声明int a,int /*p = &a后，a,\*p,\*(&a)等效
