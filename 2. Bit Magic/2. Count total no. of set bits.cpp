int countBits(int n){
        int res=0;
        while(i>0){
            i=(i&(i-1));
            res++;
        }
        return res;
    }
