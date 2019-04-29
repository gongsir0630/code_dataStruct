/*
设线性表存于A[1..size]的前num各分量中，且递增有序。
请设计一个算法，将x插入到线性表的适当位置上，以保持线性表的有序性，并在设计前说明设计思想，最后说明所设计算法的时间复杂度。
*/
void insert(int *array, int len, int x){
if(len==0){
/*array元素整体后移*/
*array = x;
return;
}
if(x<=array[len/2]) //下取整
insert(array, len/2, x);
else
insert(&array[len/2+1], len/2, x);
}
