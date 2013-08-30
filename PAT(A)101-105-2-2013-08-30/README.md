#解题思路
##Dating
主要是使用下STL的string，然后找到第一次相等，第二次相等的数值，然后控制输出格式

##Talent and Virtue
一次读入学生信息，然后归类把不同学生放到不同的vector里面，然后单独sort下，然后输出

##Set Similarity
用STL的set，然后把所有的输入维护成一个元素为set的vector

##Complete Binary Search Tree 
完全二叉树一般用数组来表示。其实这棵树的中序遍历就是一个排列好的数组，因此利用这个性质，我们把元素从小到大，依次填入CBST这个数组中。