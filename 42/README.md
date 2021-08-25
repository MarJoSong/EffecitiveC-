#Item42 �˽�typename��˫������

## Q&A ��template<>ģ������ʽ�У�class��typename��������ͬ��
## û�в�ͬ����ȫ��ͬ(�϶�~o~��)

```c
template<typename T>
void doPorcessing(T& w) {
  int x;
  if (w.size() > 0) {
    //T::const_iterator iter(w.begin()); //���뱨�������ɷ�����
    T::const_iterator * x;
    //��ȷ�Ķ���
    typename T::const_iterator iter(w.begin());
    ...
  }
}
```

�����T::const_iterator��һ�����ƣ�����ϣ����Ӧ����һ��<b>Ƕ�״�����������</b>

- ����: ��������ģ�����T
- Ƕ��: ����C�������ռ��̬��Ա��������
- ����: ����ϣ��������������ָʾ��(?)

Ƕ�״����������ƿ��ܵ��½������ѣ����룬��ģ��ʾ�����Ĺ����У�
T��һ��static��Աǡ�ɽ�const_iterator����ô����T::const_iterator * x��
����������һ��T::const_iterator*���ͣ�����һ����˱��ʽ�أ�C++�и�Ĭ�Ϲ���
�������������״̬��<b>����������Ʋ������ͣ��������������</b>
��Ҳ��������뱨���ԭ��

#### typenameֻ����������Ƕ�״�����������
```c
template<typename T>
void f(const T& tank,
	   typename T::iterator iter);  //����ʹ��typename

class Derived : public Base<T>::Nested { //��̳��б�����ʹ��typename
 public:
  explicit Derived(int x):
  Base<T>::Nested(x) {   //��Ա��ʼ���б�����ʹ��typename
    typename Base<T>::Nested temp; //���ڻ���̳��б�Ҳ���ڳ�Ա��ʼ���б������������Ҫʹ��typename
  }
};

template<typename IterT>
void workWithIterator(IterT iter) {
//std::iterator_traits<IterT>::value_type��һ������ΪIterT֮������ָ֮�������
  typedef typename std::iterator_traits<IterT>::value_type val_type;
  val_type temp(*iter); //���ģ�����IterTΪstring, temp���ͼ�Ϊstring
  
  
}
```