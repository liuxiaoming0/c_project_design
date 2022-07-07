# 知识点
完成比完美更重要

## 单例模式
- [使用场景] 系统有多个资源，但只有一个资源管理器; 公共配置类；
- [要点词语] static、delete、default、virtual、T、friend
- [异常问题] 并发，性能，如何保障不能创建多实例
- [底层保障]  
    C++11标准中的Magic Static特性：
    If control enters the declaration concurrently while the variable is being initialized, the concurrent execution shall wait for completion of the initialization.
    
    如果当变量在初始化的时候，并发同时进入声明语句，并发线程将会阻塞等待初始化结束。
    这样保证了并发线程在获取静态局部变量的时候一定是初始化过的，所以具有线程安全性。
- [核心实现]
    - 将默认拷贝构造、赋值构造删除
    - 构造函数private
    - 唯一入口获取实例：实例为static运行期不释放，实例为引用不是指针，防止提前delete
    - 尽量不用锁，减少性能损耗
- [继承实现]
    - 将子类作为模板传入，从而保证基类的getInstance( )入口可以初始化子类对象。注意这里和动态类调用的区别，由于子类构造私有，动态类仍只能获得基类对象，不是预期的子类对象；
    - 基类为友元类，因为基类GetInstance( )要调用子类的私有构造
    - 类的构造由private，改为protected，因为子类的构造前会先调基类的构造
    - 基类的析构，改为virtual