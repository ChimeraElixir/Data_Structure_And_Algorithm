class Solution(object):
    def halvesAreAlike(self, s):
        """
        :type s: str
        :rtype: bool
        """
        vowels="aeiouAEIOU"
        l=len(s)
        a=s[0:l//2]
        b=s[l//2:l+1]
        if sum(a.count(vowels) for vowels in vowels)==sum(b.count(vowels) for vowels in vowels):
            return True
        
        return False
        
