## Chapter 1: Getting Started
____
main函数接收用户的参数:
+ 第一个参数指定参数个数 (无需实参)
+ 第二个参数用来接收具体参数
  

如下代码，接收用户参数并且打印

```cpp
#include<iostream>

int main(int argc, char *argv[]){
    for(int i = 0; i < argc; i++ ){
        std::cout<<i<<": "<<argv[i]<<std::endl;
    }
}

>> .\argument.exe my_first_arg my_second_arg
0: C:\Users\brc\Desktop\CS205_CPP_Design\argument.exe
1: my_first_arg
2: my_second_arg
```
## Chapter 2: Data Types and Arithmetic Operators
___

Cpp多种初始化方式
```cpp
int a = 10;

int a;
a = 20;

int a(10);

inta{10};
```
+ 32位`unsigned int`的数值范围是 $[0, 2^{32} - 1]$
+ 32位`int`的数值范围是$[-2^{31}, 2^{31}-1]$

还有 long int, long long int类型，可以使用`sizeof(lont)`来查看具有占用多少个字节。


`char`是个一字节八位的整数，可以用`signed`和`unsigned`来修饰。在不同的平台上有不同的默认定义。

用8位的或者32位的表示字符，但是本质上是整数。

以下三行表达的含义是相同的
```cpp
char c1 = 'P';
char c2 = 80;
char c3 = '0x50';
```

cpp里面， bool 类型的 true就是1,打印出来也是1。

bool类似的sizeof 返回是一字节，因为计算机最小分配是一字节。

转bool类型的时候，只要该值不是0，那他转完之后就是1。例如bool b2 = -12; 执行完之后，b2 = 1;

size_t 这种类型用来表示**元素个数**，是个无符号整数。理论上可以用来存储任意大小。

cpp11之后明确定义了如下类型：
```cpp
int8_t
int16_t
...
uint8_t
uint16_t
...
```
还可以使用如下方式得到各个类型的最大值，最小值
```cpp
INT8_MIN
INT8_MAX
...
```

0到1之间有无穷多个数字，浮点型表示只是采样表示，因此不能用==来比较浮点数的大小


数字前面加个0,表示八进制
95l 表示为long型的
95ul或者95lu表示无符号long型的

const 限定符，表示数值不可被修改,且需要在定义的时候初始化。可以用来替代宏定义
const float PI = 3.1415926f

auto是个灵活的数据类型，具体看初始化的时候的数值类型
```cpp
auto a = 3; // int
auto b = 43.2; // double
auto c = a * 1.2 // double
auto d; // valid in c, error in cpp

auto a = 2;
a = 2.4; # 此时 a为2，因为在初始化的时候类型已经确定了。
```

类型转化,最好不要使用 implicit conversion
```cpp
int int1 = 'C';      //隐式的类型转化：讲8为的数值转为32位的
int int2 = (int)'C';  //显示的类型转化 c-style
int int3 = int('C');  // 显示的类型转化 function-style
int int4 = 2.8;   // implicit conversion
float f1 = 4.5;   // implicit conversion ：double to float
short s = 655360; // implicit conversion: 655360 to value that i do not know
```


17 / 5 是等于3的，因为17和5都是整型，如果需要浮点型，需要写为17/ 5.0

算数操作的类型只有四种：int long float double, 在运算的时候会自动转为这四种，且会尽可能的不损失数值
```cpp
unsigned a = 255;
unsigned b = 1;
int c = a + b; // c = 256, 不会因为 a b类型位 char 然后256就自动转为0 
```
## Chapter 3: Branching and Looping Statements
____

`if`语句和条件表达式 `&&,||,!`

非bool类型的数值在作为条件表达式的时候会隐式的转为bool：

+ 数值型，非0均转为 true, `-2`也是true, `0.2f``也是true
+ NULL 空指针位false

`size_t` 是恒大于等于0的。

switch语句，可以看作是在匹配label的机制，在匹配到一个case之后，会执行该case后面的所有代码，直到遇到break，因此可以把swich理解为字典树。

```cpp
int main(){
    int num = 10;
    while (1){
        cout<<"输入一个数字"<<endl;
        cin>>num;
        switch (num){
            case 1:
                cout<<"1";
                break;
            case 2:
                cout<<"2";
                break;
            default:
                break;
        }
    }
}
```

## Chapter 4: Data Structures

____

### 一维数组

固定长度的数组 int num[5], 可以使用 {}来初始化。当完全不初始化的时候，默认是任意值；但是使用{}初始化部分值的时候，剩余值为 0

变长数组（代码运行的时候才能确定数组长度）int num[arr_len]。边长数组的可否初始化具体看编译器是否支持。

数组的长度未明确学出来：

+ int num[] = {4, 3, 5}; 编译器会根据初始化的长度来定义数组长度；
+ 用在 给函数传参数的时候，传递 `(int num[], size_t length)`或者也可以`(int *num, size_t, length)`

array 赋值只能通过 元素来一个个的赋值，下述代码会报错：

```cpp
int num1[4] = {3, 4, 5, 6};
int num2[4];

num2 = num1; //error

```

在 c/c++ 中读取数组是没有边界检查的，如果越界了，编译没有报错，运行时具体看情况。即光看结果的话是意识不到程序出错的！！见如下代码：

```cpp

int main(){
    int num1[4] = {3, 4, 5, 6};
    // 虽然只定义了长度为4的数字，但是可以对下标为-1的位置操作，可读可写！
    // num1[-1] 是自动往前偏移，（1是往后的方向）
    for(int i=-1; i<4; i++){
        num1[i] = i * i; 
    }

    for (int i = -1; i<4; i++){
        cout<<num1[i]<<" ";
    }
    return 0;
}
```

c /cpp 中数组不是对象，数组可以看作是指针，是首地址的指针，但是大小不知道。优点是效率高，因为不检查边界，缺点是容易出错。

越界就相当于是野指针了，只不过这里这个野不是真的野，是有规律的野。

### 二维数组

未知长度的二维数组传参，要带列的长度。即传递二维数组的时候，需要在数组名这里就指定列数，即`(int mat[][5], size_t row, size_t, col)`

以为内存是一维的，只能以一维的方式来存储(假设每个元素占四字节)，如下：

| value |  index  | Addres |
| :---: | :-----: | :----: |
|   3   | \[1][1] |  p+12  |
|   2   | \[1][0] |  p+8   |
|   1   | \[0][1] |  p+4   |
|   0   | \[0][0] |  p+0   |

如果不指定列数，就不知道偏移量，也就无法知道第`i`行从哪开始。因此很多时候会采用一维数组来表示二维数组，然后手动计算偏移量，这样数据管理起来会较为容易。

### 常量数组 const array

用const 来修饰 数组`const float num[5]={2f, ...}`，可以防止数组被修改。一般用在数组作为函数参数的时候，可以防止误操作。

### 字符串

分为 arrat style string 和 string class 两种来介绍

#### array string

```cpp
int main(){
    
    // 后面的 默认为 0 （ascii 的 0）
    char rabbit[15] = {'r', 'a', 'b', 'b', 'i', 't'};
    // 作为数组来看，没问题，
    // 但是如果看作是字符串就不太好，因为字符串的结束标志约定俗成的是个null(即'\0')
    //如果后面没有 '\0'，直接 cout<<bag_pig 会越界。
    char bag_pig[9] = {'P', 'e', 'p', 'p', 'a', ' ', 'P', 'i', 'g'};
    // 最后的作为标志字符串结尾的标识符，是ascii 的0.
    char good_pig[10] = {'P', 'e', 'p', 'p', 'a', ' ', 'P', 'i', 'g', '\0'};
    
    return 0;
}
```

`strlen(const char *str)` 方法可以返回 array-style 字符串的长度，原理是计算该数组*起始到 '\0'*之间的字符数量，如果没有'\0'字符，就会越界查找'\0'，所有运行时可能会被os杀掉。

```cpp
char s[4] = {'b', 'a', '\0', 'i'};
// 遇到 '\0'就终止了
>>stren(s)
2
```

如果字符串不方便一个一个字符的初始化，可以使用 string literals ，这可以看作是常量字符串。

```cpp
char namer[] = "bai rui chang";
char name2[] = "ABCD";
```

原理是先数一下有多少个字符，然后+1，再初始化数组。+1是因为会保存`'\0'`。所以name2的数组长度为5，但是字符串长度为4

字符串的拷贝 函数`strcpy(char *dest, const char *src)`,会拷贝 src字符串的所有字符，而不管dest数组能否放得下，因此是不安全的。所有有了另外一个安全的版本`strncpy(char *dest, const char *src, size_t count)` 最后一个参数表示最多拷贝count 个字符，一般设置 src 和 dest长度的最小值

#### string

string 类是封装的class，出错的几率更低，且更加方便。`std:string s = "hust";`

可以使用 + 来实现字符串的相加，用 < 来实现字符串的大小比较。

但是， string 的[]索引同样没有边界检查，可以用下标来访问越界的内存。例如

```cpp
std::string s = "hust";
cout<<s[100]<<endl; // 编译不会报错
```

但是`s.at()`算是有边界检查的，编译不报错，但是在运行时报错，相对更加安全。

#### struct

```cpp
struct Student {
    char name[4];
    int born;
    bool male;
};

//两种 赋值方式

//1. 先定义再赋值
struct Student stu;
strcpy(stu.name,"Bai");
stu.born= 1997;

//2. 也可以定义的时候初始化
struct Student stu = {"Yu", 1997}
```

注意，这里如果是c语言的话，定义struct变量的时候，不能省略struct关键字。c++可以省略。在c中，可以使用typedef来新定义一个数据类型，达到省略struct的目的，代码如下：

```cpp
typedef
struct _Student {
    char name[4];
    int born;
    bool male;
} Student;
```

结构体内存对齐，下述两段代码，结构体虽然组成一样，但是元素顺序不一样，因此内存占用长度不一样，因为有内存对齐。

```cpp
#include<iostream>
#include<string.h>
using namespace std;


typedef
struct Student1 {
    int id;
    bool male;
    char label;
    float height;
} Student1;

typedef
struct Student2 {
    int id;
    bool male;
    float height;
    char label;
} Student2;

int main(){
    
    cout<<sizeof(Student1)<<" "<<sizeof(Student2)<<endl;
    return 0;
}

12 16
```

因为内存为了高效，是把地址尽量和4的倍数对齐。在student1中，id从地址0开始，male从4开始，label从5开始，height从 8开始，因此最终占用12字节。注意，label后面空了两个字节。

而student2 是male 后面空了三个字节，label后面空了三个字节。

一般的系统是 4 对齐。

在c语言中，struct就是数据的结合，如果想要定义一个结构体变量，需要加上struct，如果不想加，那就需要先 typdef。但是在cpp中，struct和class 相差不大，所以typedef在cpp中也就不需要了

#### Union

整个联合体内共享内存，所以一个联合体的大小是由联合体内部最大的变量决定。也就是说，对一块内存，有多种查看方式。一个经典的用法是用在ip地址的表示上，union里面一个32位的变量，还有一个4个元素每个元素1字节的数组。可以有两种查看ip地址的方式，同时，给ip地址赋值也方便

#### enum

定义一些颜色什么的，用来替代const数组。

枚举只是列举，因此不能用来计算

## Chapter 5: Memory and Pointer

____

指针是个存储地址的整数，这个整数可能是8位，也可能是4位，和编程环境有关系。（4字节32位最多寻址4GB）

指针的申明一般会在变量的前面加个 `*`

指针变量里面存储的是 **地址**，是内存地址。

&是个取地址的符号，放在变量前面，就是拿到这个变量存放的地址。

```cpp
int a = 20;
int * b = NULL; // 定义两个指向int类型的指针
int * c = NULL;


// b 和 c 指向了同一块内存
b = &a; // 指针 b 指向 a
c = &a; // 指针 c 指向 c

cout<< a <<endl;
cout<<*b<<endl;  // 使用指针去取他指向的值
cout<<*c<<endl;

return 0;
```

注意上述代码，b和c虽然都指向同样的内存空间，但是b和c本身也是变量，本身的存储地址是不一样的，可通过 `&b` 和 `&c`来查看

上面的是指针指向基本数据类型，那指针指向结构体对象呢？//使用指针两种访问结构体成员有两种方法：

```.cpp
struct Student{
    int born;
    char name[4];
};

Student stu = {1997, "Bai"};
Student * pstu = & stu;

//使用指针两种访问结构体成员的方法：

cout <<(*pstu).born; // *pstu 其实就和 stu一样的
cout<<pstu->born;  // pstu是指针，需要使用 -> 来访问结构体成员
```

### 指针的指针

指针是个变量，这个变量也可以再用一个变量来存储，

```cpp
int num = 10;
int p = &num;
int **pp = NULL
pp = &p; //指向指针的指针

//如何通过 pp 来修改 num 呢？
// *pp 即pp的内容，是指针p
//*(*pp)是 *pp的内容即 p的内容，也就是num值
```

### 常量指针和指针常量

常量指针，不能通过该指针修改指向内存的值

```cpp
int num = 1;
const int *p = &num; // 表示没法通过 指针修改num的值
*p = 10;   // error 不能通过该指针来修改
num = 10;  // ok
```

一般用在函数传递参数的时候，int foo(const char * p) 表示了该函数没法通过这个指针来修改指针指向的值，即通过指针只能读，没法修改



指针常量，这个指针是个常量了，不再是变量了，即这个指针不能再指向别的地方了

```cpp
int num = 1;
int * const p2 = & num;
*p2 = 10;      // ok
p2= & another; // error 这个指针不能再指向别的地方了
```

还有一种是 `const int * const p = & num；`buff加满了。

### 指针和数组

数组名可以看作是指针，且<u>对数组取地址</u>和直接把数组名打印出来是一样的。即**对数组名取地址还是他本身**。

```cpp
Student students[100];
// 以下三行结果是一样的
cout<< students<<endl;
cout<<&students<<endl;
cout<<&students[0]<<endl;

// 同时，可以把数组地址赋给另外一个指针，再通过[]索引数组元素
Student *p = students;
p[0].born = 2012;
p[1].born = 2123;
```

### 指针的代数操作

对指针 + num 表示偏移 num个元素，不是指num个字节，具体偏移多少字节，要看指针的类型

```cpp
int nums[4] = {0, 1, 2, 3};
int * p = num + 1; // 指针 p 此时指向了数组 第二个元素,值为1的元素
p ++ ; // 此时指向了第三个元素
*p = 20;
*(p-1) = 10;
p[1] = 30; // 把 3 改为了30

// p[i] 和 *(p+i) 是一样的
```

```cpp
int num = 10;
int*p= &num;
p[-1] = 20; // 越界了
*(p-1) = 20; //越界了
```

指针和数组的区别：

+ 数组是一个常量指针，不能再指向别的地方了。但是指针可以任意乱指。
+ 对数组sizeof 可以得到整个数组占用的内存大小，但是对指针的话只能得到 4 or 8

### 指针和内存

程序的内存结构：

+ 代码段， 二进制代码，只读不可写
+ 数据段，初始化的静态变量，全局变量等
+ bbs，未初始化的静态变量
+ 堆 heap，动态申请的内存
+ 堆栈 stack， 存放临时变量，局部变量

一般而言，堆 和 堆栈相向而行，一旦相遇即表示用完空间。

c语言风格的内存申请：

```cpp
// 函数原型是：
void * malloc(size_t size)
//这是未初始化的，且没有类型的
//使用的时候需要转化为对用的类型，即类型转化,例如申请 int 型空间：
int *p =  (int *) malloc(sizeof(int));
```

c语言分格的内存释放

```cpp
//函数原型
void free(void *ptr);
// 
free(p)
```

cpp分格的内存申请

```cpp
// new 和 new[];
// 不仅仅是申请内存，还可以做初始化
int * p1 = new int;
int * p2 = new int(5); // 初始化为 5
int * p3 = new int(); // 初始化为0
int * p4 = new int{};
int * p4 = new int{5};

//Student 是个结构体，cpp中结构体和class基本一样的
Student * s1 = new Student;
Student * s2 = new Student{"Bai", 2123};  //cpp11

//数组
int *pa1 = new int[16]; // 不做初始化
int *pa1 = new int[16]{}; // 初始化 置0
int *pa1 = new int[16]{1, 2, 3}; // 初始化 ，后面置0 

//结构体数组
Student * sa = new Student[16]{{"Bai", 323}, {"Bai", 23}};
```

注意：在对数字初始化的时候，可使用()，但是对结构体、数组等初始化的时候就得使用{}，因此{}功能更加多，所以较为推荐

cpp分格的内存释放

```cpp
// 对数字或者结构体或者class 直接释放即可
delete p1;
// 对数组 有两种方式
delete [] pa1;
delete pa2;
// 前者会调用数组内所有元素的析构函数，后者只会调用数组首元素的析构函数
```

## Chapter 6: Basics of Functions

函数的本意是为了 代码复用，减少重复修改的次数，当然还可以使得代码更加整洁。

```cpp
#include<iostream>

using std::cout;
using std::endl;

struct Matrix{
    int row;
    int column;
    float * pData;  
};

float getMax(const Matrix * mat){
    float maxM = __FLT_MIN__;
    for(int i = 0; i < (*mat).row; i++){
        for (int j =0; j <(*mat).column; j ++){
            float val = (*mat).pData[i * mat->column + mat->row];
            maxM = maxM > val? maxM : val;
        }
    }
    return maxM;
}

int main(){
    Matrix matA = {2, 3};
    matA.pData = new float[matA.row * matA.column]{1.f, 2.f, 3.f};

    Matrix matB = {1, 2};
    matB.pData = new float[matB.row * matB.column]{100.f, 300.f};

    cout<<"MatA的最大值为"<<getMax(&matA)<<endl;
    cout<<"MatB的最大值为"<<getMax(&matB)<<endl;
    
    return 0;
}
```

上述代码中，先定义了一个矩阵结构体，定义的时候，矩阵值使用一个指针变量来表示，有个好处就是，这个指针变量可以指向任意地方，而不像数组名。然后在初始化的时候，让这个指针指向一个数组即可。

还有参数传递的时候，也使用值传递提高效率。

函数定义需要放在调用前面，或者前面声明也可以。因为编译的时候是从上往下编译的。

声明的时候，参数名字可以省略。

当然，函数调用是由代价的！压栈入栈等

### 函数传参

由两种参数传递方式：

+ 值传递
+ 引用传递

#### 值传递：

+ 基本类型作为参数的时候，传进去的是一份拷贝，不管是数值，还算地址，都是一份拷贝，地址的拷贝或者数值的拷贝。只不过传递的地址的话，可以通过该地址修改函数外面的值，但是传递数值的话没法修改。这里注意，传递指针的话，传进去的指针和外面的指针是同一个变量，函数参数这个指针可以指向别的地方但不会改变函数外面的指针。

+ 结构体类型作为参数，传进去的也是一份拷贝（浅拷贝，如果结构体内有指针的话，指针的那部分要理解为传递的指针）。但是如果结构体里面有指针变量的话，那么这两个拷贝有着相同的指针指(指针变量的值是一样的，这里相当于是指针传递了)，即可以通过修改这个拷贝的指针来修改函数外面结构体指针指向的内容。

指针传递也是值传递的一种，这里的值是**指针**这个变量。

```cpp
func(int * p); //形参

func(& data) // 实参
```



#### 引用传递

引用传递只在cpp中有。引用定义如下：

```cpp
int num = 10;
// & 放在类型后面就不再是取地址了，而是引用。
// 表达的意思的是 numref 是num的一个别名，就是一块内存有两个名字，平起平坐的两个名字，对他们取地址之后，地址是相同的。
int & numref = num; 
```

结构体类型的引用

```cpp
struct Matrix{
    int row;
    int col;
    float * pData;
}

Matrix matA = {2, 3};
matA.pData= new float[matA.row * matA.col]{3,23,12,12};

Matrix & matA_ref = matA;  
```

注意：引用是个别名，指针是新定义一个指针变量，指向这个内存。

引用定义的时候一定要初始化，后面就没法初始化了，后面也没法改变引用对象了，语法上做不到。

引用的对象一定要和定义的引用变量类型相同，且没法引用到常数上

即一定要初始化到一个具体的对象上面，因此更加的安全。

```cpp
float getMax(Matrix & mat); // 形参

getMax(mat); // 实参
```

引用传递会修改函数外面的值，因为是同一个东西。如果想要防止修改可以添加`const`关键字:

```cpp
float getMax(const Matrix & mat); // 形参
```

const修饰的引用变量没法被修改，且也没法再被非const 引用变量引用。

```cpp
// const 引用 可以引用非const对象
//可以初始化一个const引用来对 变量的函数进行引用
int i = 0;
const int & r1 = i;
const int & r2 = i * 2;
int int & r3 = i * 5; // error
```

引用和指针的区别：

+ 引用创建的时候就必须初始化
+ 引用无法被初始化为空

+ 引用一旦创建，无法再被赋值。

+ sizeof(reference) 得到的是该变量的内存占用，sizeof(pointer) 得到的是指针的内存占用 (4byte or 8byte)



### 函数返回

值返回，返回之后，函数中的临时变量就会死亡：

+ 基本数据类型，数值被拷贝一份返回去
+ 指针变量，指针被拷贝一份返回去
+ 结构体类型，整个结构体被拷贝返回

不要返回临时变量的地址或者引用

### 内联函数

函数调用是由代价的，会有栈操作和指针移动。

inline 修饰的函数 ，在编译的时候会把指令塞到调用的地方，典型的以空间换取时间。但是只是建议，编译器不一定会遵从建议。

宏是编译预处理阶段做一个文本替换，仅仅是文本替换，在遇到 `num++`  这样的文本时，可能会执行多次 `num++`.且宏中的变量一定要加括号

## Chapter 7: Advances in Functions

### 默认 arguments

严格来说`int func(int num, float val = 0.0);` 这行代码中， val 称为 parameter , 后面的 0.0 称为 argument。只是在中文中习惯都叫做参数。

又两个原则：

+ 默认参数一定要从尾部开始定义
+ 不能重复定义默认参数

默认参数一定要从尾部开始定义，但是又例外，如：

```cpp
float norm(float x, float y, float z);
float norm(float x, float y, float z=0.0);
float norm(float x, float y=0.0, float z);
```

上述代码是可以运行的，但是第二行删掉或者第二行第三行兑换顺序之后就会报错了。可以看作效果叠加了。

此外，不能重复定义某一个参数的默认参数。 

函数声明和函数定义 只能有一个有默认参数，一般写在函数声明位置。

### 函数重载

函数重载只有cpp中有！

编译器查找的时候，是依赖参数（argument-dependent lookup, ALD）的查找，但是返回值类型不会考虑

**函数重载，不应该有歧义**

函数重载，一旦让编译器为难不知道选择哪个函数的时候就会报错（比如说，定义了 add(int, int) add(int, float) 两个函数，而调用的时候，却使用了add(2, 4.5)， 这种让编译器为难的，就会报错）.

但是如果没有重载，只有一个函数实现，此时，类型传错也仅仅只会有个警告，编译器会自动进行类型转换，然后调用那个唯一的函数。

### 函数模板

函数重载是使用了相同的函数名字，对于使用者来说，只需要记住同一个名字即可。
而函数模板是用来同一套函数名字、函数实体逻辑，只是类型不同。

本小节讲了函数模板的实例化和特例化，此外函数模板也是可以重载的。

如果仅仅是写了个函数模板，编译的时候，不会生成任何函数，因为类型还不知道，很多指令没法确定（比如 整形和浮点型的加法指令就不一样）。需要实例化函数模板，编译器才会 实例化这个函数。

即函数模板是个虚的，必须实例化一个实实在在的函数，编译器才会生成具体对应的指令。实例化有两种：

+ 显式的实例化：专门写一行代码来实例化一个函数
+ 隐式的实例化：调用的时候，根据传入的参数来实例化

```cpp
// 定义一个函数模板
template <typename T>
T add(T num1, T num2){
    cout<<"The type of num1 is :"<<typeid(T).name()<<endl;
    return num1 + num2;
}

// 显式的实例化

//有了这 三个实例化， 编译器就会生成三个 不同参数的函数，就像三个重载的函数
template double  sum<double>(double, double);

template char sum<>(char, char);

template int sum(int, int);

//隐式的实例化

// <int> 指明了 T 是 int ，所以传入的参数会顺便做隐式类型转换
cout<<add<int>(2.4f, 5.6f)<<endl;
// <> 都省略了，那么直接根据 参数类型来 隐式的实例化
cout<<add(2.4f, 4.2f)<<endl;
```

函数模板可以为某一种特定的类型开个后门，称为特例化（ specialization），比如我依旧使用上述的函数模板 sum，但是我的数据类型是个结构体Point，显然，+ 运算符是不支持结构体相加的，那么此时可以专门写一个 Point类型的sum (当然，也可以重载一个+好运算符，后面会讲):

```cpp
struct Point{
    int x;
    int y;
};

// 注意下面 特例化的语法 和前面显式实例化的区别，特例化 template 后面有一对尖括号<>
//而实例化是没有尖括号的。
template<>
Point sum<Point>(const Point &p1, const Point &p2){
    cout<<"The input type is:" << typeid(pt).name()<<endl;
    Point p;
    p.x = p1.x + p2.x;
    p.t = p1.y + p2.y;
    return p;
}
```

 ### 函数指针

函数指针是一个指针，是指向函数的指针，或者说，这个指针指向 <u>指令区域的数据</u>。

先来学语法：

```cpp
// 有如下两个函数
float norm_l1(float x, float y);
float norm_l2(float x, float y);

// 定义函数指针
float (*norm_ptr) (float x, float y); //注意这里类型一定要弄对

// 给函数指针赋值
// 一种是直接 把函数名字赋给 指针，另外一种是取地址后赋给，效果是一样的！
norm_ptr = norm_l1;
norm_ptr = & norm_l1;



// 使用,
// 一种是直接调用函数，另外一种是 可以加个*
float len1 = norm_ptr(-3.0f, 5.6f);
float len2 = (*norm_ptr)(-3.4f, 4.5f);

```

不管是使用还是调用，都有两种方式，都是等价的。 

函数指针一般用来把函数作为参数，比如回调函数



### 函数引用

```cpp
// 有如下两个函数
float norm_l1(float x, float y);
float norm_l2(float x, float y);

// 定义函数引用
float (&norm_ptr) (float x, float y) = norm_l1; //注意这里类型一定要弄对,且引用必须初始化，函数引用也不例外
```

函数引用就是函数的一个别名，使用的时候，就当作普通的函数使用即可。

## Chapter 8: Speedup Your Program



## Chapter 9: Basics of Classes

构造函数的初始化列表

构造函数的调用它时期是相同的，不管是动态申请的还是在内存中申请的。

但是析构函数的调用是不一样的：

+ 对于在栈上的变量，离开当前作用域就自动执行析构函数，

+ 对于堆上的动态申请的变量，需要手动执行delete

注：对于动态申请的数组。 Student *p = new students[5]，需要delete [] p ; 如果只是 delete p；虽然也可以释放掉所有内存，但是仅仅会执行students[0]的析构函数，数组中后面变量的析构函数不会被执行

class 实例化后的对象中 函数成员具体的指令只有一份， 不会每次实例化一个对象，就把函数成员拷贝一份。也就是说，每个对象中，只有数据成员是独有的，函数成员是所有对象共享的。函数成员在执行的时候，为了区别具体是哪个对象在调用，有一个隐藏的参数，this， 指向调用者。然后成员函数一般没有歧义的话会省略写 this ->，但是有些时候，参数和成员变量名字相同，所以会加上 this -boin = boin；



表示一个常量，可以使用宏，也可以使用 const 修饰 为常量。const的常规用法：

+ const int * p;  int const * p 表示指针指向的内容不能透过该指针修改

+ int * const p ; 表示该指针不能再指向别的地方。是个常量指针。
+ 用在参数传递时防止被修改，func(const int * p) func(const int &)
+ 类内 修饰成员变量和成员和函数：
  + const int PMI = 24; 
  + int func() const { // 函数体} 注意这里放到后面的，因为放到前面就和返回类型有歧义了。
    不可以通过该函数修改对象的成员变量！

静态 static 成员，是不绑定到某一个具体的实例上面的，即不管有几个对象，静态成员只有一个：

+ 静态 成员变量，静态成员变量在class 中只是声明，需要在class外面定义
+ 静态函数只能 对静态成员 做修改。因为调用静态成员的时候，可能一个实例对象都没有





## Chapter 10: Advances in Classes









## Chapter 11: Dynamic Memory Management in Classes









## Chapter 12: Class Inheritance











## Chapter 13: Class Templates and std Library









## Chapter 14: Error Handling









## Chapter 15: Nested Classes and RTTI
