class Solution:
    def isValid(self, s: str) -> bool:
      stack = []
      for char in s:
        if char=='(' or char == '{' or char == '[':
          stack.append(char)
        else:
          if len(stack)==0:
            return False # as  char left but a closing tag found
          if char == '}' and stack[-1]=='{':
            stack.pop()
          elif char == ')' and stack[-1]=='(':
            stack.pop()
          elif char==']' and stack[-1]=='[':
            stack.pop()
          else:
            return False # unwanted input

      return len(stack)==0