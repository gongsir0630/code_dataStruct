/*
�����Ա����A[1..size]��ǰnum�������У��ҵ�������
�����һ���㷨����x���뵽���Ա���ʵ�λ���ϣ��Ա������Ա�������ԣ��������ǰ˵�����˼�룬���˵��������㷨��ʱ�临�Ӷȡ�
*/
void insert(int *array, int len, int x){
if(len==0){
/*arrayԪ���������*/
*array = x;
return;
}
if(x<=array[len/2]) //��ȡ��
insert(array, len/2, x);
else
insert(&array[len/2+1], len/2, x);
}
