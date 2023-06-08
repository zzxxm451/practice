
```python
for i in range(0,9):
    print(i)
```




### 交换数值


```python
a=2
b=4
print(a,b)
a,b=b,a
print(a,b)
```

    2 4
    4 2



```python
a=1
b=2
c=3
a,b,c=c,c,a
print(a,b,c)
```

    3 3 1


### py里的函数可以设置默认值
**没有默认的形参需要写在有默认值的形参前面**


```python
def fun(a,b=2):
    print(a,b)
fun(1)
```

### 在函数内改变全局变量


```python
a=None
def fun():
    global a#必须要global 
    a=20
print(a)
fun()
print(a)
```

    None
    20


### python的读写文件


```python
#写文件
text = 'the first\nthe next'
file=open('file.txt','w')#open是python自带的如果没有这个文件那么会创建
file.write(text)
file.close()#一定要关文件
```

### 追加文字


```python
aa = '\n追加内容'
file=open('file.txt','a')#append追加
file.write(aa)
file.close()
```

### 读取文件


```python
file = open('file.txt','r')
content = file.read()#将file内容存在content中   有多种读取方式 
print(content)
```

### input 可以获得键盘输入值并且返回的类型是字符串

  

#### append   可以追加元素


```python
a = [0,2]
print(a)
a.append(3)
print(a)
```

    [0, 2]
    [0, 2, 3]




#### a.insert(c,b)  在a的c位置插入b

#### a.remove(b) 会减去第一个出现的b
若没有则会报错

数组的最后一位的索引号为 -1

print(a[b:c])输出a中索引号从b到c  
若从头开始可省略b 从末位开始同理  若为负数则是倒数

index可以获得数组的索引  a.index（2）获取元素2的索引号 第一次
count 可以获得元素出现几次  a.count(3)
reverse 可以排序 若a.reverse=True 则从大到小

### import 加载模块

import time as t 加载time模块并命名为t
使用 t.localtime

from time import time,localtime 从time模块中只引入了time和localtime

from time import * 引入所有模块 但使用时可以省略time.

### 错误处理 try


```python
file = open('复习.txt','w')
file.write('今日复习')
file.close()
```

 ### 列表
 #### 增加元素


```python
s=[1,2,3,4]
print(s)
s.append(5)# 只能添加单个
print(s)
s.extend([6,7])# 可以添加一个可迭代对象
print(s)
```

    [1, 2, 3, 4]
    [1, 2, 3, 4, 5]
    [1, 2, 3, 4, 5, 6, 7]



```python
s=[1,2,3,4]
s[len(s):]=[6]
print(s)
s[len(s):]=[7,8]
print(s)
```

    [1, 2, 3, 4, 6]
    [1, 2, 3, 4, 6, 7, 8]


### s.clear()会清除列表

### 列表  改


```python
s=[1,2,3]
s[1:]=[4,5,6,7]
print(s)
```

    [1, 4, 5, 6, 7]


### 列表排序
倒序  reverse（）
顺序  sort（）

### 查


```python
s=[1,2,3,4]
s.index(4)
```




    3



#### 列表拷贝

##### 浅拷贝


```python
s=[1,2,3,4]
s1=s.copy()
print(s1)
s1=s[:]
print(s1)
```

    [1, 2, 3, 4]
    [1, 2, 3, 4]


**列表的乘法是重复列表**
eg s*2 输出 [1, 2, 3, 4 ，1, 2, 3, 4]

### 在python中 赋值运算是把变量与数值进行挂钩 即引用


```python
x=[1,2,3]
y=x
x[1]=1
y
```




    [1, 1, 3]



即如下图
<img src="./picture/1.png" width="300">


```python
x=[1,2,3]
y=x.copy()
x[1]=1
x,y
```




    ([1, 1, 3], [1, 2, 3])



copy方法拷贝的是整个列表
不仅仅是变量的引用
如图
<img src='./picture/2.png' width=300>

#### 切片也是浅拷贝




```python
import copy
x=[[1,2,3],[4,5,6],[7,8,9]]
y=copy.copy(x)#参数可以是元组，字符串，列表等
x[0][1]=0
print(x)
print(y)
```

    [[1, 0, 3], [4, 5, 6], [7, 8, 9]]
    [[1, 0, 3], [4, 5, 6], [7, 8, 9]]


### 深拷贝   copy模块


```python
import copy
x=[[1,2,3],[4,5,6],[7,8,9]]
y=copy.deepcopy(x)
x[1][1]=0
print(x)
print(y)
```

    [[1, 2, 3], [4, 0, 6], [7, 8, 9]]
    [[1, 2, 3], [4, 5, 6], [7, 8, 9]]


<img src='./picture/3.png' width=300>

浅拷贝效率比深拷贝高

### 列表推导式

列表推导式是用c语言运行的 通常效率比循环快一倍


```python
#循环
a=[1,2,3,4]
for i in range(len(a)):
    a[i]*=2
#列表推导式
a=[i*2 for i in a]
```


```python
# 推导式
x=[i for i in range(10)]
# 循环
x = []
for i in range(10):
    x.append(i)
```




    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]



**注** 循环是通过迭代一个个修个值    
推导式是创建新列表再赋值为原先的这个变量名

#### 条件表达式的优先级比所有运算都低

### 推导式可以添加if语句筛选
先执行for语句 再执行if 最后执行表达式


```python
x=[i for i in range(10) if i%2==0]
x
```




    [0, 2, 4, 6, 8]



推导式还可以嵌套

#### 元组
既可以容纳不同数据也有字符串不可变性

不可修改

支持下标访问

只需要逗号隔开，可以不带括号

尽量都带括号

### 元组打包与解包

生成一个元组就叫打包

将一个元组内的每个元素分别赋值一个变量叫解包

元组的解包 左边的变量数量必须和右边元素数量一致 不然会报错




```python
tuple = (112,"lkplp",'六')
a,b,c=tuple
a,b,c
```




    (112, 'lkplp', '六')



一个字符串也可以解包


```python
a,b,c='一二三'
a,b,c
```




    ('一', '二', '三')



**多重赋值原理就是先进行打包再进行解包**


```python
x,y=1,2
x,y
```




    (1, 2)



**如果元组的元素是列表，那么还可以直接修改元组里的列表**

### 序列

列表包括列表，元组，字符串

可以分为可变序列（列表），不可变序列（元组，字符串）

`+` `*`可以用于序列

`+`用于拼接

`*`用于重复


```python
(1,2,3) * 3
```




    (1, 2, 3, 1, 2, 3, 1, 2, 3)




```python
(1,2,3)+(4,5,6)
```




    (1, 2, 3, 4, 5, 6)




```python
a=[1,2,3]
a * 4
```




    [1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3]



### 字典 {'键':'值'}

#### 创建字典

1. a={'键':'值'}
2. b=dict{键='值'}#键不能加引号
3. c=dict([('键','值')])
4. d=dict({'键':'值'})
5. e=dict({'键':'值'},键='值')#可以不同种混合
6. f=dict(zip(['键'],['值']))

#### 字典推导式

### 集合 
 无序 
 唯一


```python
type({})#字典
```




    dict




```python
type({'23'})#集合
```




    set




```python
#创建集合
{'123'}#直接创建
{s for s in '123'}#推导式
set('123')#类型构造器
```




    {'1', '2', '3'}



唯一性  便于去重


```python
s=[1,2,3,4,1,1]
set(s)#变成去重后的集合
```




    {1, 2, 3, 4}




```python
s=[1,2,3,4,1,1]
len(s)==len(set(s))
```




    False



**集合分为可变集合和不可变集合（frozenset）**

### 函数

 位置参数

 关键字参数

 默认参数

 收集参数

用help查看函数参数列表会有`/`

`/`左侧必须是位置函数

局部变量会覆盖全局变量



#### 修改作用域外的变量

nonlocal

eg 
nonlocal a

a=1

就可以修改作用域外a的值

外层函数的作用域会通过某种形式保存下来

内层函数可以记住外层函数作用域

函数只有在定义和调用时才需要括号 其余情况只需要写名字

#### 闭包
可以保存函数数据


```python
def outer():
    x=0
    y=0
    def inner(x1,y1):
        nonlocal x,y
        x+=x1
        y+=y1
        print(f"现在，X={x},y={y}")
        #注意f
        #等价于print("现在，X=,",x,",y=",y) 
    return inner
change = outer()
change(1,2)
change(1,2)
change(-2,4)
```

    现在，X=1,y=2
    现在，X=2,y=4
    现在，X=0,y=8


#### 装饰器
在不修改代码的前提下实现后加的需求


```python
print("                  \n\
             A               \n\
            / \              \n\
           I   I             \n\
           I   I             \n\
         O O  O  O           \n\
        O O O O O O          \n\
       O O O O O O O         \n\
      O O O O O O O O        \n\
           I   I             \n\
          ooooooo\n")
```


                 A               
                / \              
               I   I             
               I   I             
             O O  O  O           
            O O O O O O          
           O O O O O O O         
          O O O O O O O O        
               I   I             
              ooooooo



### lambda表达式
是个匿名函数但不是常规的函数

是个表达式而不是语句

#### 生成器

#### 递归
效率不如迭代 

### with

with遇到错误还会执行下面语句 可以保证文件正常关闭


