## Item41 了解隐式接口和编译器多态

### 类和模板都支持接口和多态
### 对类来说接口是显式的，以函数签名为中心。多态则是通过virtual函数发生与运行期
### 对模板来说接口是隐式的，奠基于有效表达式，多态则是通过类具现化和函数重载解析发生于编译器

#### 示例
```c
template<typename T>
void doPorcessing(T& w) {
  if (w.size() > 10 && w != someNastyObj)
    ...
}
```
对上述示例而言，w在进行实例化的时候要满足下面的约束条件
- T应该支持size成员函数，可以由其基类继承而来。
- size()应该返回一个int型。
- size()可以不返回int型，应该返回一个可以隐式转换到int的数值类型。
- size()可以不返回数值类型，应该返回一个定义有operator>的类型。
- size()可以不返回定义有operator>的类型，应该返回一个类型为X的对象，其加上一个int(10)必须能够调用operator>运算符。
- size()可以不返回类型为X的对象，应该返回其他对象，只要存在从该对象到X对象的隐式转换。
- T应该支持operator!=运算符重载，其参数应该是someNastyObj对应的类型。
- T应该支持operator!=运算符重载，其参数可以是X类型，但需要存在从someNastyObj对应的类型到这个类型的隐式转换。
- T可以不支持operator!=运算符重载，其应该可以被隐式转到到Y类型，Y支持operator!=运算符重载，其参数应该是someNastyObj对应的类型。
- T可以不支持operator!=运算符重载，其应该可以被隐式转到到Y类型，Y支持operator!=运算符重载，其参数也可以是能够隐式转换到someNastyObj对应类型的类型。