	
//作用域描述程序中可访问标识符的区域.一个C变量的作用域可以是块作用域、函数作用域、函数原型作用域或文件作用域.,到目前为止,本书程序实例中使用的变量几乎都基友块作用域.块是用一对花括号括起来的代码区域.
//例如,一个函数体是一个块, 函数中的任意妇科语句是一个块.定义在块中的变量具有块作用域.块作用域的可见范围是从定义处到包含该定义的块的末尾.另为,虽然函数的的形式函数声明在函数的左或括号前,但是他们也具有块作用域.属于函数体这个块.
//所以到目前为止,我们使用的局部变量(包括函数的形式参数)都具有块作用域.
                      //作用域分为 块作用域 函数原型作用域 文件作用域
//先前已经锁了块作用域的作用域效果,函数原型作用域的原理也差不过
//首先我们要知道什么是函数原型.函数原型就是 定义在 int main() 函数以前的那个函数原型的声明语句
//可以见的他们里面的形参也是有参数名的,而这个参数名的作用域只有该原型语句,换句话说就是没有什么用.
//但是值得注意的是,如果在函数原型中定义一个需要数组类型的参数的话,要确保写在数组函数中的 下标形参,的作用是属于该 函数原型作用域的.也就是说,该函数模型中定义的数组类型的参数中的下标名称不许是在该函数原型中声明的.
//除了 块作用域、函数原型作用域、还有文件作用域.
//文件作用域我们就见的多了,文件作用域的变量,就是声明在 int main 函数意外的变量 他并不属于特定的函数,所用甚至不属于 main 函数,它是属于文件的,所以只有在所有的函数都运行完毕的时候 该文件才会被清除. 同时文件作用域的变量,也叫做全局变量.

// C 变量中有着 3 种谅解属性: 外部链接、内部链接、无连接.
//这里讲到的链接其实算是一种文件作用域的实际功能的补充,也就是说 链接 说明了作用域的实际作用就是限制该改变量能够被什么样的文件,又或是函数链接使用.
//在这里要明确的是到 具有文件作用域的变量是可以被 该文件目录下的所用的 .c 文件做访问的,也就是说该变量虽然存在于个特定的文件中但是可以被其他的文件所链接到,并访问该变量.
//这里要有一个很重要的知识点,就是 static 关键字, static 关键字是静态的意思,也就是说 static 可以别用来修饰一个文件变量,使其变成一个是属于该文件才能访问的文件变量,因为默认(即: 不加 static 修饰的)文件变量是默认全文件访问的,也就是具有外部链接,而添加 static 可以关闭 文件变量的 外部链接功能,让文件变量呈现 内部链接的属性.使的该文件变量只有本文件可以访问.


// C 对象有 4 种存储期: 静态存储期、线程存储期、自动存储期、动态分为存储期
//这里引入的存储期的改变,或句话说就是说该变量在内存中的生存期,有点像 Swift 中的 ARC 的工作机制.
//文件变量语句 静态存储期,所有文件变量都具有静态存储期,也就是所只有在该程序完全退出的时候,该文件变量才会被从内存中清除.
//所有的文件变量都具有静态存储期,不管它有没有被 static 所修饰.被 static 所修饰的 文件变量,只具有内部链接属性,但是还是与默认的文件变量所具有的外部链接的文件变量一样,具有静态存储期,静态存储期,应该是存储在内存中的特定区域的.
//线程存储期的作用就是使用与多次线程的程序所准备的.程序在执行时 可以被分为多个线程,具有线程存储期的对象,从被声明的时候起到现成结束都会一直存在.用关键字 _Thread_local 声明一个对象时,每个线程都会获得私有的备份.
//这里关于线程的只是不了解.
//块作用域的变量通常都是具备自动存储期的.块作用域的变量的内存生存去时 在当程序进入该代码代码块时 为程序为该变量分配内存,而在该变量所存在的代码块运行完毕时,与该代码块一同被退出.也就是块作用域的变量与它所存在的代码块时绑定的.与代码块的启用一起加载,与代码块的运行结束一起退出.
//其中就只有数组有些不同,因为数组所占据的内存空间连续的栈,所以理论上它优化会更激进一点,数组在内存中的生存周期是在该 数组的声明语句开始到当前的块末尾结束.也就是比一般的变量的生存期少了一点.
//在函数声明的变量具备块作用域,但是块作用域也可以声明静态类型,也就是所在程序开始运行时就为该变量分配内存空间了,即使只有有运行到该函数时才能时用 该变量名进行访问该内存地址.
//但是这样又何必呢?白白浪费宝贵的内存空间?但是事实上并不是这样的,只要一个变量被分配了内存空间就可以对他进行操作.但是前提是你知道该内存空间的位置.所以可以在执行该代码块的时候通过返回值或者指针来将该静态变量传递给其他的函数使用.这样的间接使用可以是变量的初始化更加灵活.
//寄存器的概念有别与内存,内存的概念我们很熟悉,而寄存器个概念与内存很形似,只不过寄存器是存在与 cpu 当中,并且寄存器的空间十分宝贵,声明一个变量存储在 cpu 的寄存器当中的语法为,在定义变量是使用 register 关键字声明.

//一般来说定义在函数中的变量都具有自动存储期.自动存储期也是默认的块作用域的存储期.但是为了明确的表示自己的意图,也可以是 auto 关键字来表示自动存储期
//auto 关键字在C++中的用法完全不同,如果要编写 C++ 兼容的代码文件,千万不要使用 auto 语句



