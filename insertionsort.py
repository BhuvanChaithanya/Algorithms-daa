class Solution:
    def insert(self, alist, index, n):
        #code here
        pass
        
    #Function to sort the list using insertion sort algorithm.    
    def insertionSort(self, alist, n):
        for i in range(n-1):
            ele = alist[i+1]
            while(alist[i] > ele and i>=0):
                alist[i+1] = alist[i]
                i = i-1
            alist[i+1] = ele
