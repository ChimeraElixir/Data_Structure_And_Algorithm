for (const string& s : arr) {
    int a = 0, dup = 0;
    for (char c : s) {
        dup |= a & (1 << (c - 'a'));
        a |= 1 << (c - 'a');
    }
    
    if (dup > 0)
        continue;
}