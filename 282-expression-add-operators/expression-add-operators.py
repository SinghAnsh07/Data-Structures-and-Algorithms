class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        res = []
        
        def dfs(cur_idx, cur_res, cur_sum, prev):
            # Agar hum string ke end tak pahunch gaye
            if cur_idx >= len(num):
                # Check karo ki sum target ke equal hai ya nahi
                if cur_sum == target:
                    res.append("".join(cur_res))
                return
            
            # Har possible substring (digit group) try karenge
            for i in range(cur_idx, len(num)):
                cur_str = num[cur_idx: i + 1]  # Current substring
                cur_num = int(cur_str)         # Integer me convert
                
                # Leading zero wale numbers avoid karo (e.g., "05")
                if len(cur_str) > 1 and cur_str[0] == '0':
                    break

                # Agar result abhi empty hai (pehla number)
                if not cur_res:
                    # Pehle number ko directly add karo (koi operator nahi)
                    dfs(i + 1, [cur_str], cur_num, cur_num)
                else:
                    # '+' operator lagao
                    dfs(i + 1, cur_res + ["+"] + [cur_str], cur_sum + cur_num, cur_num)
                    # '-' operator lagao
                    dfs(i + 1, cur_res + ["-"] + [cur_str], cur_sum - cur_num, -cur_num)
                    # '*' operator lagao (pehle prev ko remove karo phir multiply ka result add karo)
                    dfs(i + 1, cur_res + ["*"] + [cur_str], cur_sum - prev + (prev * cur_num), prev * cur_num)
        
        # DFS shuru karo index 0 se
        dfs(0, [], 0, 0)
        return res
