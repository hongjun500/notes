--------------------------------
数组							|
--------------------------------
	# 存储一系列相同的值
		* 数组在内存中是连续存储的,所有成员在内存中的地址是连续的
	
	# 数组属于构造数据类型
		* 一个数组可以分解为多个数组,这些数组元素可以是基本数据类型或者构造类型
		* 按照数据元素的不同,数组可以分为:数值数组,字符数组,指针数组,结构数组等类别

	# 使用下标来访问数据的元素,下标从0开始
		* 使用数组最好不要越界
		* 编译器不会去检查数组下标是否正确
	# 数组定义
		int nums[10];

		* 如果使用变量来定义数组长度,那么尽量使用常量(部分编译器差异会导致编译失败)
			int len = 10;
			int arr[len];	//在不同的编译环境可能会编译失败
		* 使用 #define 或者 const 都可以

	# 可以使用表达式,常量,变量来初始化数组成员
		int arr[10];
		arr[0] = 1;
		arr[1] = 1 + 1;
		int num = 4;
		arr[2] = num;
	
	# 数组的初始化
		* 直接初始化所有值
			int arr[5] = {1,2,3,4,5};

		* 部分初始化,未初始化部分为0
			int arr[5] = {1,2,3}	//角标3,4为0

		* 数组全部初始化为0
			int arr[5] = {0}

		* 如果直接初始化所有值,那么可以不用声明数组长度
			int arr[] = {1,2,3,4,5}

		* 未初始化的数组,默认值是随机数
		* 直接初始化时,如果成员数量与数组长度不一致会异常

	# 数组名,就是首元素的地址
		int arr[5] = {1,2,3,4,5};
		printf("%p,%p",arr,&arr[0]);	//0061FF1C,0061FF1C
			
	
	# 计算数组长度
		//5个长度的int类型数组
		int arr[5] = {1,2,3,4,5};
		//计算出int的字节大小
		size_t int_size = sizeof(int);
		//计算出数组的字节大小
		size_t arr_size = sizeof(arr);
		//总大小 / 元素的大小,获得数组的长度
		int arr_length = arr_size / int_size;

		printf("int大小=%d,数组大小=%lu,数组长度=%d\n",int_size,arr_size,arr_length);//int大小=4,数组大小=20,数组长度=5

		printf("数组长度=%d\n",sizeof(arr) / sizeof(arr[0]));						//数组长度=5


	# 数组名称是常量,不能修改
		int arr[4];
		arr = 10; //error

--------------------------------
二维数组						|
--------------------------------
	# 二维数组的定义

		int arr[2][4];	//2个元素的数组,里面每个元素都是4个长度的数组

		* 内存是没有多维的这种概念,多维数组其实就是特殊的一维数组
		* 特殊的一维数组里面的元素,又是数组元素
	
	# 二维数组的初始化
		* 直接初始化
			int arr[2][3] = {{1,2,3},{4,5,6}};

			* 没有被初始化的元素为0
				int arr[][2] = {{1}}	//只有arr[0][0] = 1,其它的都是 0
					
		
		* 匹配模式的初始化
			int arr[2][3] = {1,2,3,4,5,6}
			
			* 先把123放入了第0个元素的0,1,2角标,再把456放入了第1个元素的0,1,2角标
			* 反正就是挨着放,结果跟 {{1,2,3},{4,5,6}} 是一样的,就是省略了里面的大括号而已
		
		* 初始化所有元素
			int arr[2][3] = {0}
			
			* 所有元素都初始化为0
			
		* 如果是直接初始化的方式(上面两张方式),那么第一个[](一维数组)可以不用手动的声明元素个数
			int arr[][3] = {1,2,3,4,5,6}

			* 一共有6个元素,每个2维数组的长度是3 , 6 / 3 = 2,所以就计算出了一维数组的长度

			* 没有初始化的元素为0
				int arr[][3] = {1,2,3,4,5};
				[0][0]=1
				[0][1]=2
				[0][2]=3
				[1][0]=4
				[1][1]=5
				[1][2]=0	//没有初始化的元素为0
			
	
	# 数组是常量,不能修改
		int arr[5][10];
		arr = 10; //error
	
	# 二维数组的长度计算
		* 原理分析
			int arr[5][10];
			sizeof(arr)			//10 * 5 * 4 = 200
			sizeof(arr[0]);		//10 * 4 = 40;
			sizeof(arr[0][0]);	//4
		
		* 计算代码
			int arr[][5] = {{1,2,3},{4,5,6}};

			//1,先计算出单个元素的字节大小
			int item_size = sizeof(arr[0][0]);
			//2,计算出二维数组的大小
			int two_dimensional_size = sizeof(arr[0]);
			//3,计算出一维数组的大小
			int one_dimensional_size = sizeof(arr);

			//二维数组的长度 = 二维数组的大小 / 单个元素的大小
			int two_dimensional_length = two_dimensional_size / item_size;
			//一维数组的长度 = 一维数组的大小 / 二维数组的大小
			int one_dimensional_length = one_dimensional_size / two_dimensional_size;

			printf("一维数组长度:%d,二维数组长度:%d",one_dimensional_length,two_dimensional_length);

			return EXIT_SUCCESS;

	# 数组名,就是首元素[0][0]的地址
		int arr[][5] = {{1,2,3},{4,5,6}};
		printf("%p,%p",arr,&arr[0][0]);		//0061FF08,0061FF08

--------------------------------
传递数据给函数					|
--------------------------------
	# 想要在函数中传递一个一维数组作为参数,必须以下面三种方式来声明函数形式参数
	# 这三种声明方式的结果是一样的,因为每种方式都会告诉编译器将要接收一个整型指针
	# 同样地,也可以传递一个多维数组作为形式参数

	# 方式 1
		* 形式参数是一个指针
			void func(int *param){
			}
	
	# 方式 2
		* 形式参数是一个已定义大小的数组
			void myFunction(int param[10]){
			}
	
	# 方式 3
		* 形式参数是一个未定义大小的数组：

			void myFunction(int param[]){
			}