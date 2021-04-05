#include<stdio.h> 
int totalNQueens(int n) {

int stack[100] = {0};
int col[100] = {0};
int left[100] = {0};
int right[100] = {0};
int nums = 0, j, begin = 0, top = -1;
bool result = false;

stack[++top] = 0;
col[top] = 1;
left[top] = 1;
right[top+n] = 1;

if (n == 1) 
    result = true;

while (top != -1) {
    // output
    if (result == true) {
        nums++;
        result = false;
    }
    // backtrack
    else {
        for (j = begin; j < n; j++) {
			// push
            if (col[j] != 1 && left[top+1+j] != 1 && right[top+1-j+n] != 1) {
                stack[++top] = j;
                col[j] = 1;
                left[top+j] = 1;
                right[top-j+n] = 1;
				begin = 0;
                break;
            }
        }
		// pop
		if (j == n) {
			col[stack[top]] = 0;
            left[top+stack[top]] = 0;
            right[top-stack[top]+n] = 0;
			if (top == 0 && stack[top] != n-1) {
				stack[top]++;
				col[stack[top]] = 1;
				left[top+stack[top]] = 1;
				right[top-stack[top]+n] = 1;
				begin = 0;
			}
			else {
				begin = stack[top]+1;
				stack[top] = 0;
				top--;
			}
		}
			
        else if (top == n-1) result = true;
    }
     
}
return nums;
}
int main(){
	for(int i=1;i<10;i++){
		printf("%d    %d\n",i,totalNQueens(i));
	}
}
