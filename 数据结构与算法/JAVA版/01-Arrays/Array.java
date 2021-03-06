public class Array<E> {
    private E data[];
    private int size; // 数组实际所占空间
    // private int capacity; // 直接可以用data.legth来表示


    // 构造函数，传入数组的容量capacity构造Array
    public Array(int capacity) {
        // data = new E[]; // 泛型数组不支持这样初始化
        data = (E[]) new Object[capacity];
        size = 0;
    }

    // 无参数的构造函数，默认数组的容量capacity=10
    public Array() {
        this(10);
    }

    // 获取数组的容量
    public int getCapacity() {
        return data.length;
    }

    // 获取数组中的元素个数
    public int getSize() {
        return size;
    }

    // 返回数组是否为空
    public boolean isEmpty() {
        return 0 == size;
    }

    // 在index索引的位置插入一个新元素e     index[0,size]  O(N)
    public void add(int index, E e) {
        if (index < 0 || index > size) { // 插入位置越界
            throw new IllegalArgumentException("Add failed. Require index [0,size].");
        }
        if (size == data.length) { // 数组满 动态增长
            resize(2 * data.length);
        }
        for (int i = size - 1; i >= index; --i) {
            data[i + 1] = data[i];
        }
        data[index] = e;
        size++;
    }

    // 将数组空间的容量变成newCapacity大小  O(N)
    private void resize(int newCapacity) {
        E[] newData = (E[]) new Object[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        data = newData;
    }

    // 向所有元素后添加一个新元素   O(1)
    public void addLast(E e) {
        add(size, e);
    }

    // 在所有元素前添加一个新元素   O(N)
    public void addFirst(E e) {
        add(0, e);
    }

    // 获取index索引位置的元素  index[0,size)
    public E get(int index) {
        if (index < 0 || index >= size) {
            throw new IllegalArgumentException("Get failed. Index is illegal.");
        }
        return data[index];
    }


    // 修改index索引位置的元素为e
    public void set(int index, E e) {
        if (index < 0 || index >= size) {
            throw new IllegalArgumentException("Set failed. Index is illegal.");
        }
        data[index] = e;
    }

    // 查找数组中是否有元素e
    public boolean contains(E e) {
        for (int i = 0; i < size; ++i) {
            if (data[i].equals(e)) {
                return true;
            }
        }
        return false;
    }

    // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
    public int find(E e){
        for (int i = 0; i < size; ++i) {
            if (data[i].equals(e)) {
                return i;
            }
        }
        return -1;
    }

    // 从数组中删除index位置的元素, 返回删除的元素
    public E remove(int index){
        if (index < 0 || index >= size) { // index ∈ [0,size)
            throw new IllegalArgumentException("Remove failed. Index is illegal.");
        }
        E res = data[index];
        for (int i = index + 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
        size--;
        data[size] = null;   // loitering objects != memory leak

        if (size == data.length / 2) { // 动态的缩小数组
            resize(data.length / 2);
        }
        return res;
    }

    // 从数组中删除第一个元素, 返回删除的元素
    public E removeFirst(){
        return remove(0);
    }

    // 从数组中删除最后一个元素, 返回删除的元素
    public E removeLast(){
        return remove(size - 1);
    }

    // 从数组中删除元素e
    public void removeElement(E e){
        int index = find(e);
        if (index != -1) {
            remove(index);
        }
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append("Array:size = " + getSize() + "  , capacity = " + data.length + "\n");
        res.append('[');
        for (int i = 0; i < size; ++i) {
            res.append(data[i]);
            if (i != size - 1) {
                res.append(", ");
            }
        }
        res.append(']');
        return res.toString();
    }
}
