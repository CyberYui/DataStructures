对于只在表的首尾两端进行插入操作的线性表，宜采用的存储结构是(C)<br>
A. 顺序表<br>
B. 用头指针表示的单循环链表<br>
C. 用尾指针表示的单循环链表<br>
D. 单链表<br>
[解析] 本题考查的是线性表的插入与删除操作.当线性表用尾指针表示的单循环链表存储时,很容易找到线性表的首,尾元素.此时,尾指针的后继即是线性表的首端.<br>

若最常用的操作是读取线性表中某个位置元素的值,则采用(A)存储方式最节省时间
A．顺序表 
B．双链表 
C．单循环链表 
D．单链表
[解析]线性表中最常用的操作是取第i个元素,所以,应选择随机存取结构即顺序表,同时在顺序表中查找第i个元素的前趋也很方便.
单链表和单循环链表既不能实现随机存取,查找第i个元素的前趋也不方便,双链表虽然能快速查找第i个元素的前趋,但不能实现随机存取.

设顺序表有19个元素,第一个元素的地址为200,且每个元素占3个字节,则第14个元素的存储地址为(B)
A. 242
B. 239
C. 245
D. 236
[解析]顺序表中,元素的地址保存的是首地址,所以第一个元素位于200~203,其后加13*3即第14个元素的地址,即239,这表示第14个元素位于239~242.