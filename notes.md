## 关键概念
1.**静态类型：**c++是一种静态类型语言，在编译阶段检查类型。其中，检查类型的过程称为类型检查。
## chapter1
### 1.5 类
1.Every **class defines a type**. The type name is the same as the name of the class.  
As with the builtin types, we can define a variable of a class type.   
2.点运算符只能用于类类型的对象
## chapter2
### 2.1基本内置类型
1.**（无符号数只能>=0）**A signed type represents negative or positive numbers (including zero);
an unsigned type represents only values greater than or equal to zero.  
2.signed char和unsigned char就仅仅是取值范围不同, 一个[-128,127], 一个[0,255]char可能是两者中任意一个  
3.Use an unsigned type when you know that the values cannot be negative.  
3.unsigned+int=unsigned+(unsigned)int
[编译器会先将int变成unsigned再处理]  
4.切勿混用符号类型与无符号类型，因为带符号数会被自动转换成无符号类型再做运算  
5.默认情况下，十进制字面值是带符号数，八进制和十六进制字面值既可能带符号也可能无符号。  
### 2.2
1.Initialization is not assignment  
2.c++11新标准：用花括号初始化变量得到了全面应用  
3.建议初始化每一个内置类型的变量，以保证程序安全，因为未初始化的变量含有一个不确定的值。  
**4.变量声明和定义的关系：**To obtain a declaration that is not also a definition, we add the extern keyword and may not provide an explicit initializer  
Variables must be defined exactly once but can be declared many times.
```
extern int i; // declares but does not define i
int j; // declares and defines 
extern double pi = 3.1416; // definition
```
5.变量命名规范：用户自定义的类名一般以大写字母开头，如Sales_item  
### 2.3 复合类型
#### 2.3.1 引用
- Technically speaking, when we use the term reference, we mean “lvalue reference.”（左值引用） 
```
int ival = 1024;
int &refVal = ival; // refVal refers to(指向) (is another name for) ival
int &refVal2; // error: a reference must be initialized
``` 
1.When we define a reference, instead of copying the initializer’s value, **we bind the reference to its initializer**. Once initialized, a reference remains bound to its initial object. **There is no way to rebind a reference to refer to a different object. Because there is no way to rebind a reference, references must be initialized.**
A reference is not an object. Instead, a reference is just another name for an already existing object  
2.定义了一个引用之后，对其所有的操作都是在与之绑定的对象上进行的：
```
refVal = 2; // assigns 2 to the object to which refVal refers, i.e., to ival
int ii = refVal; // same as ii = ival

// ok: refVal3 is bound to the object to which refVal is bound, i.e., to ival
 int &refVal3 = refVal;
 // initializes i from the value in the object to which refVal is bound
 int i = refVal; // ok: initializes i to the same value as ival
```
3.引用值必须绑定在对象上，不能与字面值或某个表达式的计算结果绑定在一起  
```
int &refVal4 = 10; // error: initializer must be an object double dval = 3.14;
int &refVal5 = dval; // error: initializer must be an int object
```  
#### 2.3.2 指针
- 指针本身就是一个对象，允许对指针赋值和拷贝  
- 因为引用不是对象，没有实际地址，所以不能定义指向引用的指针  
1.The value (i.e., the address) stored in a pointer can be in one of four states:
- It can point to an object.
- It can point to the location just immediately past the end of an object.
- It can be a null pointer(空指针), indicating that it is not bound to any object.
- It can be invalid(无效指针); values other than the preceding three are invalid.  
notes：Although pointers in cases 2 and 3 are valid, there are limits on what we can do with such pointers. Because these pointers do not point to any object, we may not use them to access the (supposed) object to which the pointer points. If we do attempt to access an object through such pointers, the behavior is undefined.  
2.对指针解引用（*p）会得出所指的对象  
**3.空指针**  
```
int *p1 = nullptr; // equivalent to int *p1 = 0;
int *p2 = 0; // directly initializes p2 from the literal constant 0
// must #include cstdlib
int *p3 = NULL; // equivalent to int *p3 = 0;
```  
The most direct approach is to initialize the pointer using the literal nullptr, which was introduced by the new standard(c++11引入)，nullptr is a literal that has a special type that can be converted (§ 2.1.2, p. 35) to any other pointer type（nullptr可以被转换成任意其他的指针类型）  
4.It can be hard to keep straight whether an assignment changes the pointer or the object to which the pointer points.最好的办法是记住**赋值永远改变的是等号左侧的对象**  
```
pi = &ival; // value in pi is changed; pi now points to ival
*pi = 0; // value in ival is changed; pi is unchanged
```
**5.void*指针**  
void*是一种特殊的指针类型，可用于存放任意对象的地址。对该地址中到底是个什么类型的对象并不了解  
不能直接操作void*指针所指的对象。以void*的视角来看内存空间也就仅仅是内存空间，没办法访问空间中所存的对象

#### 2.3.3 理解复合类型的声明
1.在定义语句中，类型修饰符(*或&)并非作用于本次定义的全部变量，而是紧接着的哪个变量  
```
//合法但容易产生误导，p1是指向int的指针而p2是int
int* p1, p2  
```  
**2.指向指针的指针**  
图片：指向指针的指针  
**3.指向指针的引用**  
1.引用本身不是一个对象，因此不能定义指向引用的指针。但指针是对象，所以存在对指针的引用  
```
int i = 42;
int *p; // p is a pointer to int
int *&r = p; // r is a reference to the pointer p
r = &i; // r refers to a pointer; assigning &i to makes p point to i
*r = 0; // dereferencing r yields i, the object to which p points; changes i to 0
```
图片：指向指针的引用

### 2.4 const限定符
1.const对象必须初始化，且其值不能被改变  
2.默认状态下，const对象仅在文件内有效  
3.若想被其他文件使用，则在声明和定义时都添加extern  
#### 2.4.1 const的引用（p55）
术语：通常把“对const的引用”简称为“常量引用”
```
int i = 42;
const int &r2 = i //合法，但不允许通过r2修改i的值
```
但是i的值允许通过其他途径修改，比如直接给i赋值  
#### 2.4.2 指针与const  
1.允许一个指向常量的指针指向一个非常量对象
```
const double pi = 3.14; // pi is const; its value may not be changed double *ptr = &pi; // error: ptr is a plain pointer const double *cptr = &pi; // ok: cptr may point to a double that is const
*cptr = 42; // error: cannot assign to *cptr 

double dval = 3.14; // dval is a double; its value can be changed
cptr = &dval; // ok: but can't change dval through cptr
```  
2.所谓指向常量的指针仅仅要求不能通过该指针改变对象的值，而没有规定那个对象的值不能通过其他途径改变。  

**2.const指针**  
*const说明该指针是一个常量，即不变的是指针本身的值而非指向的那个值：  
```
int errNumb = 0;
int *const curErr = &errNumb; // curErr will always point to errNumb
const double pi = 3.14159;
const double *const pip = &pi; // pip is a const pointer to a const（指向常量对象的常量指针）(从右向左阅读)
```
**3.指向常量的指针vs常量指针**  
- 指向常量的指针：关键在于**指向的目标是一个常量**，可以改变指向，不能通过解引用修改数据
- 常量指针：不可以改变指向，但可以通过解引用修改数据  
#### 2.4.3 顶层const 
**用顶层const表示指针本身是个常量，用底层const表示指针所指的对象是一个常量；一般的，顶层const可以表示任意的对象是常量**  
顶层const需要初始化，底层const不必（练习2.28）
```
int i = 0;
int *const p1 = &i; // we can't change the value of p1; const is top-level
const int ci = 42; // we cannot change ci; const is top-level
const int *p2 = &ci; // we can change p2; const is low-level
const int *const p3 = p2; // right-most const is top-level, left-most is not
const int &r = ci; // const in reference types is always low-level
```  
#### 2.4.4 constexpr(c++11)和常量表达式  
Under the new standard, we can ask the compiler to verify that a variable is a constant expression by declaring the variable in a constexpr declaration. Variables declared as constexpr are implicitly const and must be initialized by constant expressions:  
```
constexpr int mf = 20; // 20 is a constant expression
constexpr int limit = mf + 1; // mf + 1 is a constant expression
constexpr int sz = size(); // ok only if size is a constexpr function
```  

### 2.5 处理类型  
#### 2.5.1 类型别名  
两种方法：  
1.传统方法：typedef double wages; //wages是double的别名  
2.**(c++11)别名声明：using SI = Sales_item //SI是Sales_item的同义词** 
#### 2.5.2 auto类型说明符(c++11)
auto:能使编译器替我们去分析表达式所属的类型，其定义的变量必须有初始值  
1.当引用成为auto初始值时，真正参与初始化的其实是引用对象的值，auto类型为引用对象的类型  
2.auto一般会忽略顶层const，保留底层  
#### 2.5.3 decltype类型指示符(c++11)
选择并返回操作数的数据类型  
### 2.6 自定义数据结构
#### 2.6.3 编写自己的头文件
头文件保护符  
#define #ifdef #ifndef
```
#ifndef  SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data { 
  std::string bookNo;   
  unsigned units_sold = 0; 
  double revenue = 0.0;
};
#endif
```  

## chapter3 Strings Vectors Arrays  
#### 3.2.2 string对象上的操作  
string的操作                                                                                                   
os<<s          ------  将s写到输出流os当中，返回os                
is>>s          ------  从is中读取字符串赋给s, 字符串以空白分割  
                       返回is                                    
getline(is, s) ------  从is中读取一行赋给s，返回is               
s.empyt()      ------  s为空返回true，否则为false                
s.size()       ------  返回s中字符的个数;**注意：该函数返回的事string::size_type类型，是一个无符号整型数，不要和有符号数混用**                         
s[n]           ------  返回s中第n个字符的引用                    
s1 + s2        ------  返回s1和s2连接后的结果                     
s1 = s2        ------  用s2的副本代替s1中原来的字符               
s1 == s2       ------  如果s1和s2中所含的字符完全一样，则相等；  
s1 != s2       ------                                          
<, <=, >, >=   ------  利用字符在字典中的顺序进行比较，对大小写敏感  





















