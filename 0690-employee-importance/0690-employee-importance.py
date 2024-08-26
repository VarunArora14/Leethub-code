"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        '''
        given an input id, consider that as the root, find the aggregate sum of importances of it
        and it's subordinates
        '''
        
        def dfs(employee, total, mapper):
            
            sum=0
            for s in employee.subordinates:
                sum+=dfs(mapper[s], total, mapper)
            
            total+=sum
            total+=employee.importance
            print(employee.importance)
            print("total:", total)
            return total
                
        mapper = {e.id: e for e in employees}
        
        for e in employees:
            if e.id == id:
                print("id found")
                total=0
                total = dfs(e,total, mapper)
                return total
        
        return -1
        
        
            
        
        
        
