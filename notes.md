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





