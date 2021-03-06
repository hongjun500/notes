
# 线性结构
	* 数组
	* 栈
	* 链表
	* 队列
	* 哈希表

# 树结构
	* 二叉树
	* 二分搜索树
	* AVL
	* 红黑树
	* Treap
	* Splay
	* 堆
	* Trie(前缀树)
	* 线段树
	* K-D树
	* 并查集
	* 哈夫曼树

#  图结构
	* 邻接矩阵
	* 邻接表

# 时间复杂度
	O(1)
		* 运行一次就找到了(最优的算法)

	O(n)	
		* 数据有多长就需要运行多少次
		* 数据量增大几倍,耗时也增大几倍,比如常见的遍历算法
	
	O(n^2)
		* 就代表数据量增大n倍时,耗时增大n的平方倍,这是比线性更高的时间复杂度
		* 比如冒泡排序,就是典型的O(n^2)的算法,对n个数排序,需要扫描n × n次

	O(logn)
		* 数据增大n倍时,耗时增大logn倍(这里的log是以2为底的)
		* 比如,当数据增大256倍时,耗时只增大8倍,是比线性还要低的时间复杂度

		* 二分查找就是O(logn)的算法,每找一次排除一半的可能,256个数据中查找只要找8次就可以找到目标

	O(nlogn)
		* 就是n 乘以logn
		* 当数据增大256倍时,耗时增大 256*8 =2048 倍
		* 这个复杂度高于线性低于平方,归并排序就是O(nlogn)的时间复杂度
	
	
	
	常数阶		O(1)
	对数阶		O(log2n)
	线性对数阶	O(nlog2n)
	平方阶		O(n^2)
	立方阶		O(n^3)
	k次方阶		O(n^k)
	指数阶		O(2^n)

	* 时间复杂度由小变大
