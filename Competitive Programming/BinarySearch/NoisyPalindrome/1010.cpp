bool solve(string s) {

    int l = 0, r = s.size()-1;

    while(l<=r)
    {
        while(l<=r && (s[l] < 'a' || s[l] > 'z'))
            l++;
        while(l<=r && (s[r] < 'a' || s[r] > 'z'))
            r--;

        if(l<=r && s[l]!=s[r])
            return false;
        l++;   
        r--;         
    }
    return true;
    
}
