#解题思路
##Dating
出题的意思是先比较前面两个string找到日期，然后找到小时，然后比较后面两个string，找到分钟，最后控制输出格式。

##Talent and Virtue
一次读入学生信息，放到vector里面，然后sort下，输出。  

##Set Similarity
用STL的set，然后把所有的输入维护成一个元素为set的vector.然后set其实内部是从小到大排列的。但是计算共同元素的时候，如果遍历set，需要nlog(n)时间，因此我们还是需要把每次输入的set转成vector存储起来。比较两个vector，同时从头部开始往尾部移动指针就可以了。

##Complete Binary Search Tree 
完全二叉树一般用数组来表示。其实这棵树的中序遍历就是一个排列好的数组，因此利用这个性质，我们把元素从小到大，依次填入CBST这个数组中。