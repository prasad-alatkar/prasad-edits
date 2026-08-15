bool isPalindrome(int x) {
    
    int i,j,num = 0;
    if (x < 0) return false;

    i = x;
    while(i) {
        num++;
        //i = i%10;
        i = i/10;
    }
    int high = 1, temp, low;
    for (i = num; i > 1; i--) {
        high = 10*high;
    }

    i = num, j = 1; 
    int k = x;
    while (i > j) {
        temp = k/high;
        low = k % 10;
        if ( temp != low) return false;

        k = k % high;
        k = k / 10;
        high = high/100;
        i--;
        j++;
    }
    return true;

}