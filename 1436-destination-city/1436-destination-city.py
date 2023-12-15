class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        mapper = {}
        
        for path in paths:
            src = path[0]
            dest = path[1]
            mapper[src]=dest
        
        # we know for sure a solution exists
        start = paths[0][0] # first src
        while start in mapper:
            start = mapper[start]
        
        return start