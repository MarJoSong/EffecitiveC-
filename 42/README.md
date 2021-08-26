# Item42 了解typename的双重意义

## Q&A 在template<>模板声明式中，class和typename有声明不同？
## 没有不同，完全相同(肯定！)

```c
template<typename T>
void doPorcessing(T& w) {
  int x;
  if (w.size() > 0) {
    //T::const_iterator iter(w.begin()); //编译报错，被当成非类型
    T::const_iterator * x;
    //正确的定义
    typename T::const_iterator iter(w.begin());
    ...
  }
}
```

上面的T::const_iterator是一个名称，我们希望它应该是一个<b>嵌套从属类型名称</b>

- 从属: 其依赖于模板参数T
- 嵌套: 其在C的命名空间或静态成员，方法内
- 类型: 我们希望它被当作类型指示符

嵌套从属类型名称可能导致解析困难，试想，在模板示例化的过程中，
T中一个static成员恰巧叫const_iterator，那么对于T::const_iterator * x，
到底是声明一个T::const_iterator*类型，还是一个相乘表达式呢，C++有个默认规则
来解释这个歧义状态：<b>它假设此名称不是类型，除非你明确告诉它是</b>
这也是上面编译报错的原因

#### typename只被用来验明嵌套从属类型名称
```c
template<typename T>
void f(const T& tank,
	   typename T::iterator iter);  //必须使用typename

class Derived : public Base<T>::Nested { //类继承列表不允许使用typename
 public:
  explicit Derived(int x):
  Base<T>::Nested(x) {   //成员初始化列表不允许使用typename
    typename Base<T>::Nested temp; //不在基类继承列表，也不在成员初始化列表的类型名，需要使用typename
  }
};

template<typename IterT>
void workWithIterator(IterT iter) {
//std::iterator_traits<IterT>::value_type是一个类型为IterT之对象所指之物的类型
  typedef typename std::iterator_traits<IterT>::value_type val_type;
  val_type temp(*iter); //如果模板参数IterT为string, temp类型即为string
  
  
}
```
