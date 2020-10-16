
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char * pcg = "String Literal";

int main()
{
    int auto_store = 40;
    char  auto_string [] = "Auto char Array";
    int * pi;
    char * pcl;
    
    pi = (int * ) malloc(sizeof(int));
    *pi =  35;
    pcl = (char * ) malloc(strlen("Dynamic String") + 1);
    strcpy(pcl, "Dynamic String");
    
    printf("static_store: %d at %p\n", static_store, &static_store);
    printf(" auto_store: %d at %p\n", auto_store, &auto_store);
    printf("      *pi: %d at %p\n", *pi, pi);
    printf("  %s at %p\n", pcg, pcg);
    printf("  %s at %p\n", auto_string, auto_string);
    printf("  %s at %p\n", pcl, pcl);
    printf("  %s at %p\n", "Quoted String", "Quoted String");
    free(pi);
    free(pcl);
    
    return 0;
    
}
//讨论使用 定义在头文件中的static 的常量 于定义在开文件开头的 const 的文件常量的区别.
// 在 头文件中 .h 中定义的常量必须是 static 静态的. 但是 static 来标识一个 常量还有另外一个作用那就是 内部链接, 其作用就是避免了 在 使用了这个 头文件中的文件中 还需要使用  extern 的标识符来表示该 const 常量,因为 虽然在 .h 头文件中, 但是本质上她还是属于 其他的文件,所以被标记成静态的话 , 其实就是只是在每个使用了该文件中 文件中 都拷贝了一份 该 const 常量, 所以使用 .h 头文件来 创建 常量其实是一种 偷懒的方法.当然一个 const 的常量一般也占用不了多少的内存 , 但是如果 const 常量为一个 用哟多个项的数组的话 这样的内存浪费 是不能视而不见的.

//说了 将 const 常量定义在 .h 头文件中的情况. 如果是直接将 该 const  常量定义在以一个普通的 .c 文件里面呢?
//定义咋.c 文件里面的 const 常量 算是一种文件变量 也就是说与 上面说的 定义在 .h 头文件中的不同点就是 位于头文件中的 const 常量 因为是位于 行首的所以她本是就是一个 文件常量 是存储在 静态常量中的, 但是她又是 位于在 .h 自定义头文件中的 所以与会跟随着头文件的引用而被复制.从静态存储区中拷贝到动态存储区, 相当于给每个文件都做了一个副本.而直接在 头文件中定义的文件常量存储在 静态存储区, 在需要使用的文件里面需要使用  extern 来标识出来, 实际是指应用该 地址的数据而已并没有被拷贝. 所以相对的就更加节省内存.

//关于 C 程序的优化问题
// C 程序的优化有两个重要的关键字 一个是 volatile 另为一个是 restrict 关键字
// 先说 volatile 关键字 该关键字的作用就是 标识一些只有只被少量的使用了, 带每次的使用期间都没有发生值的改变, 于是编译器就会静该值存储在 cpu 的寄存器当中, 方便在需要的时候 快速的调用, 相当于创建了一个可以快速访问的副本存储在寄存器当中. 方便快速的调用, 但是如果该值在 调用期间发生了 值的变化 ,又或者所需要赋值给指针, 那么 编译器就会那张该该程序中所发生的使用来 有选择的是否要将该值放入寄存器当中,
//也许你也注意到了 使用 volatile 关键字来进行优化程序的条件比较的苛刻 ,主要有以下的几点条件, 第一是该 值在整个的程序运行期间, 不能发生值的改变, 其次是不能被指针所指向. 所以 要想使用 volatile 关键字来优化程序, 一般都是与 const 定义的常量配可使用, 因为其优化的原理是将其值拷贝到 寄存器当中来加速值的调用. 一般的 如果是较大的 数组类型的数据就不适用了. 你的观点是主观的, 使用 volatile 关键字只是一种 引导而已, 只是告诉了编译器这里有一个数据好像是可以被优化的样子, 但是最终的还是编译器来决定是否要进行优化的.
// restrict 的原理也是差不多的, 与 volatile 不同的是 volatile 作用的是 常量, 而 restrict 则专门专用与指针的,
// restrict 的作用 就是告诉该编译器 , 该指针为访问该内存地址的为方式 ,所以编译器就会尝试着将 程序中出现有该指针的语句进行优化, 其优化的方式是件合适的语句进行整合, 将多表达式整合在一起一次执行代替多次执行.
//另为的就是 _Atomic 关键字了, 该关键字是作用于多线程程序的, 现在的我对多线程还一无所知.
//还有就是 新标准下的关于指针的修饰关键字的写法, 就是新增了使用下标方括号来填写  const 关键字,以及 restrict 关键字的语法.
//其实这样的增加也很好理解,因为数组的方括号 本来就是 指针的一种, 写在方括号中  double pio[const], 比 原理来的额 double * const pio 要明确的多.而至于 static 声明静态 的关键字. 就有一点特别了, 因为一个数组需要声明在在静态内存当中, 就必须要在定义的阶段就 指明 其实际所需的内存大小, 所以 就会从原理啊的 double static array[10],变成新语法的 double array[static 10];
