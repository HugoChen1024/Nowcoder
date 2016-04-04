//快速排序实现方法一
void quick_sort(int s[],int l,int r)//先去第一个元素作为基准，从后面比较
{
    int i = l, j = r, base = s[i];//挖坑
    while (i<j&&s[j]>base)
    {
        j--;
    }
    if (i<j)
    {
        s[i++] = s[j];//填数
    }
    while (i<j&&s[i]<base)
    {
        i++;
    }
    if (i<j)
    {
        s[j++] = s[i];
    }
    s[i] = base;
    quick_sort(s,l,i-1);
    quick_sort(s, i + 1, r);
}

//实现方法二


int patition(int gArr[], int begin, int end){
    int index, small;
    small = begin - 1;
    for (index = begin; index < end; index++){  //最后一个作为基准，从头开始比较
        if (gArr[index] < gArr[end]){
            small++;
            if (small != index)
                swap(index, small);
        }
    }
    small++;
    swap(small, end);
    return small;
}
void swap(int gArr[],int i, int j){
    int tmp = gArr[j];
    gArr[j] = gArr[i];
    gArr[i] = tmp;
}

//理解选择标准在头还是尾！