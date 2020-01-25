class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        prefix = strs[0]  # 从第1个字符串开始
        for i in range(len(strs)):
            while(strs[i].find(prefix) != 0):  # 不是其他字符串的前缀
                prefix = prefix[:-1]  # 减少前缀
                if not prefix:
                    return ""
        return prefix
