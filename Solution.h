#ifndef SOLUTION_H
#define SOLUTION_H

#include <map>
#include <set>
#include <tuple>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>

class Solution {
public:
	Solution();
	~Solution();

	Solution(Solution const&) = delete;
	Solution(Solution const&&) = delete;
	void operator=(Solution const&) = delete;
	void operator=(Solution const&&) = delete;

public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

public:
	// 1. Two Sum
	std::vector<int> twoSumOLD(std::vector<int>& nums, int target);
	std::vector<int> twoSum(std::vector<int>& nums, int target);
	// 2. Add Two Numbers
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	// 3. Longest Substring Without Repeating Characters
	int lengthOfLongestSubstring(std::string s);
	// 4. Median of Two Sorted Arrays
	double findMedianSortedArrays(std::vector<int> const& nums1, std::vector<int> const& nums2);
	double findMedianSortedArraysOld(std::vector<int> const& nums1, std::vector<int> const& nums2);
	// 5. Longest Palindromic Substring
	std::string longestPalindrome(std::string s);
	// 6. Zigzag Conversion
	std::string convert(std::string s, int numRows);
	// 7. Reverse Integer
	int reverse(int x);
	// 8. String to Integer (atoi)
	int myAtoi(std::string s);
	// 9. Palindrome Number
	bool isPalindrome(int x);
	bool isPalindrome2(int x);
	// 11. Container With Most Water
	int maxArea(std::vector<int>& height);
	// 12. Integer to Roman
	std::string intToRoman(int num);
	// 13. Roman to Integer
	int romanToInt(std::string s);
	// 14. Longest Common Prefix
	std::string longestCommonPrefix(std::vector<std::string>& strs);
	std::string longestCommonPrefixWithStructuralBinding(std::vector<std::string>& strs);
	// 15. 3Sum
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
	// 16. 3Sum Closest
	int threeSumClosest(std::vector<int>& nums, int target);
	// 17. Letter Combinations of a Phone Number
	std::vector<std::string> letterCombinations(std::string digits);
	// 18. 4Sum
	std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);
	// 19. Remove Nth Node From End of List
	ListNode* removeNthFromEnd(ListNode* head, int n);
	// 20. Valid Parentheses
	bool isValidParentheses(std::string s);
	// 21. Merge Two Sorted Lists
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
	// 22. Generate Parentheses
	std::vector<std::string> generateParenthesis(int n);
	// 23. Merge k Sorted Lists
	ListNode* mergeKLists(std::vector<ListNode*>& lists);
	// 24. Swap Nodes in Pairs
	ListNode* swapPairs(ListNode* head);
	// 25. Reverse Nodes in k-Group
	ListNode* reverseKGroup(ListNode* head, int k);
	// 26. Remove Duplicates from Sorted Array
	int removeDuplicates(std::vector<int>& nums);
	// 27. Remove Element
	int removeElement(std::vector<int>& nums, int val);
	// 28. Find the Index of the First Occurrence in a String
	int strStr(std::string haystack, std::string needle);
	// 29. Divide Two Integers
	int divide(int dividend, int divisor);
	// 30. Substring with Concatenation of All Words
	std::vector<int> findSubstring(std::string s, std::vector<std::string>& words);
	std::vector<int> findSubstringOptimizedUnfinished(std::string s, std::vector<std::string>& words);
	// 34. Find First and Last Position of Element in Sorted Array
	std::vector<int> searchRange(std::vector<int>& nums, int target);
	// 35. Search Insert Position
	int searchInsert(std::vector<int>& nums, int target);
	// 36. Valid Sudoku
	bool isValidSudoku(std::vector<std::vector<char>>& board);
	bool isValidSudoku2(std::vector<std::vector<char>>& board);
	// 37. Sudoku Solver
	void solveSudoku(std::vector<std::vector<char>>& board);
	// 38. Count and Say
	std::string countAndSay(int n);
	// 39. Combination Sum
	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);
	// 40. Combination Sum II
	std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);
	//41. First Missing Positive
	int firstMissingPositive(std::vector<int>& nums);

private:
	int expandAroundCenter(std::string const& s, int left, int right);
	int extract(Solution::ListNode*& l);
	int KMPString(std::string const& pattern, std::string const& input);
	void backtrackPhoneDigit(std::string const& input, std::string& combination,
		std::map<char, std::string> const& phoneLetters, std::vector<std::string>& output);
	std::vector<std::vector<int>> twoSumAuxiliary(std::vector<int>& nums, long long target, size_t start);
	std::vector<std::vector<int>> kSumAuxiliary(std::vector<int>& nums, long long target, size_t start, int k);

};

#endif //SOLUTION_H
