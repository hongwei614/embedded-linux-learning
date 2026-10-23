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
- 指针的算数运算
- 一维数组指针与二维数组指针

## 练习
- pointer_basic.c
- pointer_arth.c
- pointer_array.c
- pointer_tdimarray.c
- row_pointer

## 易错点
- 声明int a,int /*p = &a后，a,\*p,\*(&a)等效
- x\[i\],\*(px + i),\*(x + i),px[i]具有相同的作用，访问数组第i + 1个元素
- 数组名本身也是一个地址量，是地址常量，不能修改；指针变量能够修改
- 指针变量的大小取决于系统的地址位宽，例如，x86的指针变量大小为8字节
- 二维数组的数组名代表了起始地址，数组名加1，是移动一行，常被成为行地址，声明行地址的行指针`int a\[2\]\[3\];int (\*p)\[3\];`
  对于一个二维数组a，\*a指向二维数组中的一行一维数组；对于一个一维数组b，\*b指向b地址中的元素
  声明`int a[2][3];int (*p)[3];``a[i][j], *(a[i] + j), *(*(a + i) + j),  *(*(p + i) + j)`等价


