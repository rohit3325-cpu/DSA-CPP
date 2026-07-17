class Solution(object):
    def removeOuterParentheses(self, s):
        result=[]
        open=0
        for i in range(len(s)):
            if(s[i]=='('):
                open +=1
                if(open>1): result.append(s[i])

            elif (s[i] == ')'):
                open -=1
                if(open>0): result.append(s[i])


        return ''.join(result)            
        