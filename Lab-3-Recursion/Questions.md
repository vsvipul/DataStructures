
Lab 3: Recursion
 
1.      Using recursion search for an integer ‘a’ in a 1-D integer array. Return -1 if the element is not found.
2.      Using recursion search for an integer ‘a’ in a 2-D integer array. Return -1 if the element is not found.
3.      Make a recursive function sum(X,i,j,k,l,n) that computes the sum of a 2-D array from the index [i][j] to the index [k][l], given that 0≤i≤k<n and 0≤j≤l<n.
4.      Compute the total number of solutions to the problem of n-queens. 
        Calculate for different (some large) values of n.
 
5. In a mystic educational institute a student has 3 girlfriends! It’s the chocolate day of the Valentines week and the student has therefore purchased n chocolates, the prices of which are stored in an array X, with Xi denoting the price of ith chocolate. As an ethical rule, the student loves all the girlfriends equally and therefore wishes to distribute the chocolates among the three girlfriends such that each girlfriend receives total chocolates worth nearly the same total cost. Solve the question using backtracking. You need to minimize f(Y1,Y2,Y3)=|sum(Y1)-sum(Y2)|+|sum(Y2)-sum(Y3)|+ |sum(Y3)-sum(Y1)|, where sum(Y1) is the sum of all prices of the chocolates in the array Y1, and |.| is the absolute value function. Consider X=[2,6,9,3,1,4,10,5,7,8]. Let the three parts be Y1=[1,6,9], Y2=[5,2,8,4], Y3=[3,7,10]. The sums are given by sum(Y1)=1+6+9=16; sum(Y2)=5+2+8+4=19; and sum(Y3)=3+7+10=20. f(Y1,Y2,Y3)=|16-19|+|19-20|+|20-16|=9. For a different choice of Y1, Y2, and Y3, the objective will be different. You need to find the best split possible. 
