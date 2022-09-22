#define BOOST_TEST_MODULE TestModule
#include <boost/test/unit_test.hpp>
#include "Solution.h"

///...boost\build_boost_1_79\include\boost-1_79
///...boost\boost_build_1_79\lib

BOOST_AUTO_TEST_CASE(BasicSuccess_Test_1)
{
	BOOST_CHECK(1 == 1);
}

BOOST_AUTO_TEST_CASE(TwoSum_Test_1)
{
	Solution solution;
	std::vector<int> nums{ 2, 7, 11, 15 };
	std::vector<int> expectedOutput{ 0,1 };
	BOOST_CHECK(solution.twoSum(nums, 9) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(TwoSum_Test_2)
{
	Solution solution;
	std::vector<int> nums{ 3,2,4 };
	std::vector<int> expectedOutput{ 1,2 };
	BOOST_CHECK(solution.twoSum(nums, 6) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(TwoSum_Test_3)
{
	Solution solution;
	std::vector<int> nums{ 3,3 };
	std::vector<int> expectedOutput{ 0,1 };
	BOOST_CHECK(solution.twoSum(nums, 6) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(MedianSortedArray_Test_1)
{
	Solution solution;
	std::vector<int> nums1;
	std::vector<int> nums2;

	nums1 = { 1,3,6,7,9 };
	nums2 = { 2,4,5,8 };
	BOOST_CHECK(solution.findMedianSortedArrays(nums1, nums2) == 5.0);
}

BOOST_AUTO_TEST_CASE(MedianSortedArray_Test_2)
{
	Solution solution;
	std::vector<int> nums1;
	std::vector<int> nums2;

	nums1 = { 1,11,13 };
	nums2 = { 3,5,7,9 };
	BOOST_CHECK(solution.findMedianSortedArrays(nums1, nums2) == 7.0);
}

BOOST_AUTO_TEST_CASE(MedianSortedArray_Test_3)
{
	Solution solution;
	std::vector<int> nums1;
	std::vector<int> nums2;

	nums1 = { 1,11,13,15 };
	nums2 = { 3,5,7,9 };
	BOOST_CHECK(solution.findMedianSortedArrays(nums1, nums2) == 8.0);
}

BOOST_AUTO_TEST_CASE(MedianSortedArray_Test_4)
{
	Solution solution;
	std::vector<int> nums1;
	std::vector<int> nums2;

	nums1 = { 1,11,13,15 };
	nums2 = { 3,5,7,9 };
	BOOST_CHECK(solution.findMedianSortedArrays(nums1, nums2) == 8.0);
}

BOOST_AUTO_TEST_CASE(MedianSortedArray_Test_5)
{
	Solution solution;
	std::vector<int> nums1;
	std::vector<int> nums2;

	nums1 = { 1,11,13 };
	nums2 = { 3,5,7,9,15 };
	BOOST_CHECK(solution.findMedianSortedArrays(nums1, nums2) == 8.0);
}

BOOST_AUTO_TEST_CASE(MedianSortedArray_Test_6)
{
	Solution solution;
	std::vector<int> nums1;
	std::vector<int> nums2;

	nums1 = { 1,2 };
	nums2 = { 3,4 };
	BOOST_CHECK(solution.findMedianSortedArrays(nums1, nums2) == 2.5);
}

BOOST_AUTO_TEST_CASE(MedianSortedArray_Test_7)
{
	Solution solution;
	std::vector<int> nums1;
	std::vector<int> nums2;

	nums1 = {};
	nums2 = { 2,4,5,8,9 };
	BOOST_CHECK(solution.findMedianSortedArrays(nums1, nums2) == 5.0);
}

BOOST_AUTO_TEST_CASE(MedianSortedArray_Test_8)
{
	Solution solution;
	std::vector<int> nums1;
	std::vector<int> nums2;

	nums1 = { 2,4,5,8 };
	nums2 = {};
	BOOST_CHECK(solution.findMedianSortedArrays(nums1, nums2) == 4.5);
}

BOOST_AUTO_TEST_CASE(MedianSortedArray_Test_9)
{
	Solution solution;
	std::vector<int> nums1;
	std::vector<int> nums2;

	nums1 = { 0, 0, 0, 0, 0 };
	nums2 = { -1, 0, 0, 0, 0, 0, 1 };
	BOOST_CHECK(solution.findMedianSortedArrays(nums1, nums2) == 0.0);
}

BOOST_AUTO_TEST_CASE(MedianSortedArray_Test_10)
{
	Solution solution;
	std::vector<int> nums1;
	std::vector<int> nums2;

	nums1 = { 3 };
	nums2 = { -2, -1 };
	BOOST_CHECK(solution.findMedianSortedArrays(nums1, nums2) == -1.0);
}

BOOST_AUTO_TEST_CASE(MedianSortedArray_Test_11)
{
	Solution solution;
	std::vector<int> nums1;
	std::vector<int> nums2;

	nums1 = { 1 };
	nums2 = { 1 };
	BOOST_CHECK(solution.findMedianSortedArrays(nums1, nums2) == 1.0);
}

BOOST_AUTO_TEST_CASE(LongestPalindrome_Test_1)
{
	Solution solution;
	std::string input("abba-bab-abba");
	BOOST_CHECK(solution.longestPalindrome(input) == std::string("abba-bab-abba"));
}

BOOST_AUTO_TEST_CASE(LongestPalindrome_Test_2)
{
	Solution solution;
	std::string input("babad");
	BOOST_CHECK(solution.longestPalindrome(input) == std::string("aba"));
}

BOOST_AUTO_TEST_CASE(PuzzleString_Test_1)
{
	Solution solution;
	std::string input("PAYPALISHIRING");
	BOOST_CHECK(solution.convert(input, 3) == std::string("PAHNAPLSIIGYIR"));
}

BOOST_AUTO_TEST_CASE(PuzzleString_Test_2)
{
	Solution solution;
	std::string input("PAYPALISHIRING");
	BOOST_CHECK(solution.convert(input, 4) == std::string("PINALSIGYAHRPI"));
}

BOOST_AUTO_TEST_CASE(PuzzleString_Test_3)
{
	Solution solution;
	std::string input("A");
	BOOST_CHECK(solution.convert(input, 1) == std::string("A"));
}

BOOST_AUTO_TEST_CASE(PuzzleString_Test_4)
{
	Solution solution;
	std::string input("A");
	BOOST_CHECK(solution.convert(input, 4) == std::string("A"));
}

BOOST_AUTO_TEST_CASE(ReverseInt_Test_1)
{
	Solution solution;
	BOOST_CHECK(solution.reverse(123) == 321);
}

BOOST_AUTO_TEST_CASE(ReverseInt_Test_2)
{
	Solution solution;
	BOOST_CHECK(solution.reverse(-123) == -321);
}

BOOST_AUTO_TEST_CASE(ReverseInt_Test_3)
{
	Solution solution;
	BOOST_CHECK(solution.reverse(120) == 21);
}

BOOST_AUTO_TEST_CASE(MyAtoi_Test_1)
{
	Solution solution;
	BOOST_CHECK(solution.myAtoi("42") == 42);
}

BOOST_AUTO_TEST_CASE(MyAtoi_Test_2)
{
	Solution solution;
	BOOST_CHECK(solution.myAtoi("-42") == -42);
}

BOOST_AUTO_TEST_CASE(MyAtoi_Test_3)
{
	Solution solution;
	BOOST_CHECK(solution.myAtoi("   -42") == -42);
}

BOOST_AUTO_TEST_CASE(MyAtoi_Test_4)
{
	Solution solution;
	BOOST_CHECK(solution.myAtoi("4193 with words") == 4193);
}

BOOST_AUTO_TEST_CASE(MyAtoi_Test_5)
{
	Solution solution;
	BOOST_CHECK(solution.myAtoi("     -4193 with words") == -4193);
}

BOOST_AUTO_TEST_CASE(MyAtoi_Test_6)
{
	Solution solution;
	BOOST_CHECK(solution.myAtoi("-91283472332") == INT_MIN);
}

BOOST_AUTO_TEST_CASE(MyAtoi_Test_7)
{
	Solution solution;
	BOOST_CHECK(solution.myAtoi("91283472332") == INT_MAX);
}

BOOST_AUTO_TEST_CASE(MyAtoi_Test_8)
{
	Solution solution;
	BOOST_CHECK(solution.myAtoi("+1") == 1);
}

BOOST_AUTO_TEST_CASE(MyAtoi_Test_9)
{
	Solution solution;
	BOOST_CHECK(solution.myAtoi("00000-42a1234") == 0);
}

BOOST_AUTO_TEST_CASE(MyAtoi_Test_10)
{
	Solution solution;
	BOOST_CHECK(solution.myAtoi("   +0 123") == 0);
}

BOOST_AUTO_TEST_CASE(MyAtoi_Test_11)
{
	Solution solution;
	BOOST_CHECK(solution.myAtoi("-2147483647") == -2147483647);
}

BOOST_AUTO_TEST_CASE(IsPalindrome_Test_1)
{
	Solution solution;
	BOOST_CHECK(solution.isPalindrome(121) == true);
}

BOOST_AUTO_TEST_CASE(IsPalindrome_Test_2)
{
	Solution solution;
	BOOST_CHECK(solution.isPalindrome(-121) == false);
}

BOOST_AUTO_TEST_CASE(IsPalindrome_Test_3)
{
	Solution solution;
	BOOST_CHECK(solution.isPalindrome(10) == false);
}

BOOST_AUTO_TEST_CASE(IsPalindrome_Test_4)
{
	Solution solution;
	BOOST_CHECK(solution.isPalindrome(101) == true);
}

BOOST_AUTO_TEST_CASE(MaxArea_Test_1)
{
	Solution solution;
	std::vector<int> input = { 1,8,6,2,5,4,8,3,7 };
	BOOST_CHECK(solution.maxArea(input) == 49);
}

BOOST_AUTO_TEST_CASE(MaxArea_Test_2)
{
	Solution solution;
	std::vector<int> input = { 1,1 };
	BOOST_CHECK(solution.maxArea(input) == 1);
}

BOOST_AUTO_TEST_CASE(IntToRoman_Test_1)
{
	Solution solution;
	//std::cout << "RESULT : [" << solution.intToRoman(3) << "]\n";
	BOOST_CHECK(solution.intToRoman(3) == std::string("III"));
}

BOOST_AUTO_TEST_CASE(IntToRoman_Test_2)
{
	Solution solution;
	//std::cout << "RESULT : [" << solution.intToRoman(58) << "]\n";
	BOOST_CHECK(solution.intToRoman(58) == std::string("LVIII"));
}

BOOST_AUTO_TEST_CASE(IntToRoman_Test_3)
{
	Solution solution;
	//std::cout << "RESULT : [" << solution.intToRoman(1994) << "]\n";
	BOOST_CHECK(solution.intToRoman(1994) == std::string("MCMXCIV"));
}

BOOST_AUTO_TEST_CASE(RomanToInt_Test_1)
{
	Solution solution;
	//std::cout << "RESULT : [" << solution.romanToInt("III") << "]\n";
	BOOST_CHECK(solution.romanToInt("III") == 3);
}

BOOST_AUTO_TEST_CASE(RomanToInt_Test_2)
{
	Solution solution;
	//std::cout << "RESULT : [" << solution.romanToInt("LVIII") << "]\n";
	BOOST_CHECK(solution.romanToInt("LVIII") == 58);
}

BOOST_AUTO_TEST_CASE(RomanToInt_Test_3)
{
	Solution solution;
	//std::cout << "RESULT : [" << solution.romanToInt("MCMXCIV") << "]\n";
	BOOST_CHECK(solution.romanToInt("MCMXCIV") == 1994);
}

BOOST_AUTO_TEST_CASE(LongestCommonPrefix_Test_1)
{
	Solution solution;
	std::vector<std::string> input{ "flower","flow","flight" };
	BOOST_CHECK(solution.longestCommonPrefix(input) == std::string("fl"));
}

BOOST_AUTO_TEST_CASE(LongestCommonPrefix_Test_2)
{
	Solution solution;
	std::vector<std::string> input{ "dog","racecar","car" };
	BOOST_CHECK(solution.longestCommonPrefix(input) == std::string(""));
}

BOOST_AUTO_TEST_CASE(LongestCommonPrefix_Test_3)
{
	Solution solution;
	std::vector<std::string> input{ "leets", "leetcode", "leet", "leeds" };
	//std::cout << "RESULT : [" << solution.longestCommonPrefix(input) << "]\n";
	BOOST_CHECK(solution.longestCommonPrefix(input) == std::string("lee"));
}

BOOST_AUTO_TEST_CASE(LongestCommonPrefix_Test_4)
{
	Solution solution;
	std::vector<std::string> input{ "leetcode", "leets", "leet", "lee", "le", "lss"};
	//std::cout << "RESULT : [" << solution.longestCommonPrefix(input) << "]\n";
	BOOST_CHECK(solution.longestCommonPrefix(input) == std::string("l"));
}

BOOST_AUTO_TEST_CASE(ThreeSum_TEST_1)
{
	Solution solution;
	std::vector<int> input{ -1,0,1,2,-1,-4 };
	std::vector<std::vector<int>> expectedOutput{ {-1,-1,2},{ -1,0,1} };
	//std::vector<std::vector<int>> output = solution.threeSum(input);
	//std::string str;
	//for (auto& out : output) {
	//	str += "[";
	//	for (int& o : out)
	//		str += std::to_string(o);
	//	str += "]";
	//}
	//std::cout << "RESULT : " << str << "\n";
	BOOST_CHECK(solution.threeSum(input) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(ThreeSum_TEST_2)
{
	Solution solution;
	std::vector<int> input{ 0,1,1 };
	std::vector<std::vector<int>> expectedOutput;
	//std::vector<std::vector<int>> output = solution.threeSum(input);
	//std::string str;
	//for (auto& out : output) {
	//	str += "[";
	//	for (int& o : out)
	//		str += std::to_string(o);
	//	str += "]";
	//}
	//std::cout << "RESULT : " << str << "\n";
	BOOST_CHECK(solution.threeSum(input) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(ThreeSum_TEST_3)
{
	Solution solution;
	std::vector<int> input{ 0, 0, 0 };
	std::vector<std::vector<int>> expectedOutput{ {0, 0, 0} };
	//std::vector<std::vector<int>> output = solution.threeSum(input);
	//std::string str;
	//for (auto& out : output) {
	//	str += "[";
	//	for (int& o : out)
	//		str += std::to_string(o);
	//	str += "]";
	//}
	//std::cout << "RESULT : " << str << "\n";
	BOOST_CHECK(solution.threeSum(input) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(ThreeSumClosest_TEST_1)
{
	Solution solution;
	std::vector<int> input{ -1,2,1,-4 };
	//std::cout << "RESULT : " << solution.threeSumClosest(input, 1) << "\n";
	BOOST_CHECK(solution.threeSumClosest(input, 1) == 2);
}

BOOST_AUTO_TEST_CASE(ThreeSumClosest_TEST_2)
{
	Solution solution;
	std::vector<int> input{ 0,0,0 };
	//std::cout << "RESULT : " << solution.threeSumClosest(input, 1) << "\n";
	BOOST_CHECK(solution.threeSumClosest(input, 1) == 0);
}

BOOST_AUTO_TEST_CASE(ThreeSumClosest_TEST_3)
{
	Solution solution;
	std::vector<int> input{ 0,1,2 };
	//std::cout << "RESULT : " << solution.threeSumClosest(input, 1) << "\n";
	BOOST_CHECK(solution.threeSumClosest(input, 3) == 3);
}

BOOST_AUTO_TEST_CASE(ThreeSumClosest_TEST_4)
{
	Solution solution;
	std::vector<int> input{ 0,0,0 };
	//std::cout << "RESULT : " << solution.threeSumClosest(input, 1) << "\n";
	BOOST_CHECK(solution.threeSumClosest(input, 10000) == 0);
}

BOOST_AUTO_TEST_CASE(LetterCombinations_TEST_1)
{
	Solution solution;
	std::string input("23");
	std::vector<std::string> expectedOutput{ "ad","ae","af","bd","be","bf","cd","ce","cf" };
	//std::vector<std::string> output = solution.letterCombinations(input);
	//std::string str;
	//for (auto& out : output) {
	//	str += "[";
	//	str += out;
	//	str += "]";
	//}
	//std::cout << "RESULT : " << str << "\n";
	BOOST_CHECK(solution.letterCombinations(input) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(LetterCombinations_TEST_2)
{
	Solution solution;
	std::string input;
	std::vector<std::string> output = solution.letterCombinations(input);
	//std::vector<std::string> output = solution.letterCombinations(input);
	//std::string str;
	//for (auto& out : output) {
	//	str += "[";
	//	str += out;
	//	str += "]";
	//}
	//std::cout << "RESULT : " << str << "\n";
	BOOST_CHECK(solution.letterCombinations(input).empty());
}

BOOST_AUTO_TEST_CASE(LetterCombinations_TEST_3)
{
	Solution solution;
	std::string input("2");
	std::vector<std::string> expectedOutput{ "a","b","c" };
	//std::vector<std::string> output = solution.letterCombinations(input);
	//std::string str;
	//for (auto& out : output) {
	//	str += "[";
	//	str += out;
	//	str += "]";
	//}
	//std::cout << "RESULT : " << str << "\n";
	BOOST_CHECK(solution.letterCombinations(input) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(LetterCombinations_TEST_4)
{
	Solution solution;
	std::string input("234");
	std::vector<std::string> expectedOutput{ 
		"adg", "adh", "adi", "aeg", "aeh", 
		"aei", "afg", "afh", "afi", "bdg", 
		"bdh", "bdi", "beg", "beh", "bei", 
		"bfg", "bfh", "bfi", "cdg", "cdh", 
		"cdi", "ceg", "ceh", "cei", "cfg", 
		"cfh", "cfi" };
	//std::vector<std::string> output = solution.letterCombinations(input);
	//std::string str;
	//for (auto& out : output) {
	//	str += "[";
	//	str += out;
	//	str += "]";
	//}
	//std::cout << "RESULT : " << str << "\n";
	BOOST_CHECK(solution.letterCombinations(input) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(FourSum_TEST_1)
{
	Solution solution;
	std::vector<int> input{ 1,0,-1,0,-2,2 };
	std::vector<std::vector<int>> expectedOutput{ {-2,-1,1,2},{-2,0,0,2},{-1,0,0,1} };
	//std::vector<std::vector<int>> output = solution.fourSum(input,0);
	//std::string str;
	//for (auto& out : output) {
	//	str += "[";
	//	for (int& o : out)
	//		str += std::to_string(o);
	//	str += "]";
	//}
	//std::cout << "RESULT : " << str << "\n";
	BOOST_CHECK(solution.fourSum(input, 0) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(FourSum_TEST_2)
{
	Solution solution;
	std::vector<int> input{ 2,2,2,2,2 };
	std::vector<std::vector<int>> expectedOutput{ {2,2,2,2} };
	//std::vector<std::vector<int>> output = solution.fourSum(input, 8);
	//std::string str;
	//for (auto& out : output) {
	//	str += "[";
	//	for (int& o : out)
	//		str += std::to_string(o);
	//	str += "]";
	//}
	//std::cout << "RESULT : " << str << "\n";
	BOOST_CHECK(solution.fourSum(input, 8) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(FourSum_TEST_3)
{
	Solution solution;
	std::vector<int> input{ -1000000000, -1000000000, 1000000000, -1000000000, -1000000000 };
	//std::vector<std::vector<int>> output = solution.fourSum(input, 8);
	//std::string str;
	//for (auto& out : output) {
	//	str += "[";
	//	for (int& o : out)
	//		str += std::to_string(o);
	//	str += "]";
	//}
	//std::cout << "RESULT : " << str << "\n";
	BOOST_CHECK(solution.fourSum(input, 294967296).empty());
}

BOOST_AUTO_TEST_CASE(IsValidParentheses_TEST_1)
{
	Solution solution;
	std::string input("()");
	BOOST_CHECK(solution.isValidParentheses(input) == true);
}

BOOST_AUTO_TEST_CASE(IsValidParentheses_TEST_2)
{
	Solution solution;
	std::string input("()[]{}");
	BOOST_CHECK(solution.isValidParentheses(input) == true);
}

BOOST_AUTO_TEST_CASE(IsValidParentheses_TEST_3)
{
	Solution solution;
	std::string input("(]");
	BOOST_CHECK(solution.isValidParentheses(input) == false);
}

BOOST_AUTO_TEST_CASE(IsValidParentheses_TEST_4)
{
	Solution solution;
	std::string input("(([({})]))");
	BOOST_CHECK(solution.isValidParentheses(input) == true);
}

BOOST_AUTO_TEST_CASE(IsValidParentheses_TEST_5)
{
	Solution solution;
	std::string input("(([({})])]");
	BOOST_CHECK(solution.isValidParentheses(input) == false);
}

BOOST_AUTO_TEST_CASE(IsValidParentheses_TEST_6)
{
	Solution solution;
	std::string input("]");
	BOOST_CHECK(solution.isValidParentheses(input) == false);
}

BOOST_AUTO_TEST_CASE(GenerateParenthesis_TEST_1)
{
	Solution solution;
	std::vector<std::string> expectedOutput{ "((()))","(()())","(())()","()(())","()()()" };
	BOOST_CHECK(solution.generateParenthesis(3) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(GenerateParenthesis_TEST_2)
{
	Solution solution;
	std::vector<std::string> expectedOutput{ "()" };
	BOOST_CHECK(solution.generateParenthesis(1) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(RemoveDuplicates_TEST_1)
{
	Solution solution;
	std::vector<int> input{ 1,1,2 };
	std::vector<int> expectedOutput{ 1,2 };
	int k = solution.removeDuplicates(input);
	auto itr = input.begin();
	for (int i = 0; i < k; ++i)
		itr++;
	input.erase(itr, input.end());
	//std::string output;
	//for (int i : input) {
	//	output += std::to_string(i) + " ";
	//}
	//output = '[' + output;
	//output[output.size() - 1] = ']';
	//std::cout << output << " " << k << "\n";
	BOOST_CHECK(input == expectedOutput);
}

BOOST_AUTO_TEST_CASE(RemoveDuplicates_TEST_2)
{
	Solution solution;
	std::vector<int> input{ 0,0,1,1,1,2,2,3,3,4 };
	std::vector<int> expectedOutput{ 0,1,2,3,4 };
	int k = solution.removeDuplicates(input);
	auto itr = input.begin();
	for (int i = 0; i < k; ++i)
		itr++;
	input.erase(itr, input.end());
	//std::string output;
	//for (int i : input) {
	//	output += std::to_string(i) + " ";
	//}
	//output = '[' + output;
	//output[output.size() - 1] = ']';
	//std::cout << output << " " << k << "\n";
	BOOST_CHECK(input == expectedOutput);
}

BOOST_AUTO_TEST_CASE(RemoveElement_TEST_1)
{
	Solution solution;
	std::vector<int> input{ 3,2,2,3 };
	std::vector<int> expectedOutput{ 2,2 };
	int k = solution.removeElement(input, 3);
	auto itr = input.begin();
	for (int i = 0; i < k; ++i)
		itr++;
	input.erase(itr, input.end());
	//std::string output;
	//for (int i : input) {
	//	output += std::to_string(i) + " ";
	//}
	//output = '[' + output;
	//output[output.size() - 1] = ']';
	//std::cout << output << " " << k << "\n";
	BOOST_CHECK(input == expectedOutput);
}

BOOST_AUTO_TEST_CASE(RemoveElement_TEST_2)
{
	Solution solution;
	std::vector<int> input{ 0,1,2,2,3,0,4,2 };
	std::vector<int> expectedOutput{ 0,1,3,0,4 };
	int k = solution.removeElement(input, 2);
	auto itr = input.begin();
	for (int i = 0; i < k; ++i)
		itr++;
	input.erase(itr, input.end());
	//std::string output;
	//for (int i : input) {
	//	output += std::to_string(i) + " ";
	//}
	//output = '[' + output;
	//output[output.size() - 1] = ']';
	//std::cout << output << " " << k << "\n";
	BOOST_CHECK(input == expectedOutput);
}

BOOST_AUTO_TEST_CASE(StrStr_TEST_1)
{
	Solution solution;
	std::string haystack("sadbutsad"), needle("sad");
	BOOST_CHECK(solution.strStr(haystack, needle) == 0);
}

BOOST_AUTO_TEST_CASE(StrStr_TEST_2)
{
	Solution solution;
	std::string haystack("badbutsad"), needle("sad");
	BOOST_CHECK(solution.strStr(haystack, needle) == 6);
}

BOOST_AUTO_TEST_CASE(StrStr_TEST_3)
{
	Solution solution;
	std::string haystack("leetcode"), needle("leeto");
	BOOST_CHECK(solution.strStr(haystack, needle) == -1);
}

BOOST_AUTO_TEST_CASE(StrStr_TEST_4)
{
	Solution solution;
	std::string haystack("mississippi"), needle("issip");
	BOOST_CHECK(solution.strStr(haystack, needle) == 4);
}

BOOST_AUTO_TEST_CASE(StrStr_TEST_5)
{
	Solution solution;
	std::string haystack("mississippi"), needle("issi");
	BOOST_CHECK(solution.strStr(haystack, needle) == 1);
}

BOOST_AUTO_TEST_CASE(Divide_TEST_1)
{
	Solution solution;
	BOOST_CHECK(solution.divide(10, 3) == 3);
}

BOOST_AUTO_TEST_CASE(Divide_TEST_2)
{
	Solution solution;
	BOOST_CHECK(solution.divide(7, -3) == -2);
}

BOOST_AUTO_TEST_CASE(Divide_TEST_3)
{
	Solution solution;
	BOOST_CHECK(solution.divide(-7, -3) == 2);
}

BOOST_AUTO_TEST_CASE(Divide_TEST_4)
{
	Solution solution;
	BOOST_CHECK(solution.divide(1, 1) == 1);
}

BOOST_AUTO_TEST_CASE(Divide_TEST_5)
{
	Solution solution;
	BOOST_CHECK(solution.divide(1, -1) == -1);
}

BOOST_AUTO_TEST_CASE(Divide_TEST_6)
{
	Solution solution;
	BOOST_CHECK(solution.divide(INT_MAX, 1) == INT_MAX);
}

BOOST_AUTO_TEST_CASE(Divide_TEST_7)
{
	Solution solution;
	BOOST_CHECK(solution.divide(INT_MIN, -1) == INT_MAX);
}

BOOST_AUTO_TEST_CASE(Divide_TEST_8)
{
	Solution solution;
	BOOST_CHECK(solution.divide(INT_MIN, 1) == INT_MIN);
}

BOOST_AUTO_TEST_CASE(Divide_TEST_9)
{
	Solution solution;
	BOOST_CHECK(solution.divide(2147483647, 2) == 1073741823);
}

BOOST_AUTO_TEST_CASE(Divide_TEST_10)
{
	Solution solution;
	BOOST_CHECK(solution.divide(2, 2) == 1);
}

BOOST_AUTO_TEST_CASE(Divide_TEST_11)
{
	Solution solution;
	BOOST_CHECK(solution.divide(-2147483648, 2) == -1073741824);
}

BOOST_AUTO_TEST_CASE(FindSubstring_TEST_1)
{
	Solution solution;
	std::string input("barfoothefoobarman");
	std::vector<std::string> words{ "foo","bar" };
	std::vector<int> expectedOutput{ 0,9 };
	//std::string output;
	//for (int& i : solution.findSubstring(input, words)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.findSubstring(input, words) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(FindSubstring_TEST_2)
{
	Solution solution;
	std::string input("wordgoodgoodgoodbestword");
	std::vector<std::string> words{ "word","good","best","word" };
	std::vector<int> expectedOutput;
	//std::string output;
	//for (int& i : solution.findSubstring(input, words)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.findSubstring(input, words).empty());
}

BOOST_AUTO_TEST_CASE(FindSubstring_TEST_3)
{
	Solution solution;
	std::string input("barfoofoobarthefoobarman");
	std::vector<std::string> words{ "bar","foo","the" };
	std::vector<int> expectedOutput{ 6,9,12 };
	//std::string output;
	//for (int& i : solution.findSubstring(input, words)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.findSubstring(input, words) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(FindSubstring_TEST_4)
{
	Solution solution;
	std::string input("wordgoodgoodgoodbestword");
	std::vector<std::string> words{ "word","good","best","good" };
	std::vector<int> expectedOutput{ 8 };
	//std::string output;
	//for (int& i : solution.findSubstring(input, words)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.findSubstring(input, words) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(FindSubstring_TEST_5)
{
	Solution solution;
	std::string input("aaa");
	std::vector<std::string> words{ "aa","aa" };
	std::vector<int> expectedOutput{};
	//std::string output;
	//for (int& i : solution.findSubstring(input, words)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.findSubstring(input, words).empty());
}

BOOST_AUTO_TEST_CASE(FindSubstring_TEST_6)
{
	Solution solution;
	std::string input("amxbtipvhwzyytfnekijzdvutiweyhcyvbbqjqosonrmiwcoikxjpsfiacpbltbjudbfvpxkfqypoaeykbibwpkyrbzfubqqgrvbhunonmdbmhazlkahbmftnfajiqbohwpqtdegpkjdtlcevfnxttsjausikuytsnklsqtjcdnworcmyslsndbpzvzjrxekmqxfhrqlwfjkxowxgjptmsilqhwhebtsrtxakqoivxsulrsrajmpewcufbbjexexqbaarokplejzxbsanfprdtljwoualyybcydvonkzsuapxtpkagddcomydhbqfbsjzvfplpodlrujkkvkszpupcvulwlsxdcyahnlydqkulvexqqprgmhkhdvdopatrawanhzqajnletkwmzoslxeuazxrozkiziimqhfqqudwnntzojtcgzwiywzpvmzxuhjmrqejmjgaybbnkxrqwpaxlaojongkwrxnkdxwnfylgaaqztivjiuwkihaxnluhkjrninanoovoonpixmtghpsrzvrmgnvqwmfhcguqusgkfvsdhnlqdfkcabqiooamagteoqwiieupzpsjcfbhlllnmcwcswpseizsyvcgaxwbmqmoyqwlbjyqnwsfvhyzqzsowuxyrvafnouleswibxyptswoauqsviiscfqwcsbqhxbnravvxvksoghodziahqslyljaflsokwccwzxtvjnjrwzwvhxczrqxezakmsyxoabkcyfxjtiaphznqyppphnwhngtheswhtijtqiclqfcxepnchctorpvgxroejmlfwwymebzwgctmtiqcmlrebokahaetmryjnwxtzzphdktwulzhxsnaizaqafjowhxmfxhfwzmzlixgtwnqqcszbtrbaaqyjpkomuvktijgqhmlfbeydwzfrqirsaqbqcreynptxaapjmarogptdoawgjoyjgzbksgjhxcexcthpwyfcpahfbelmujvckzmcfvkcyqbckktikamzbweecpqwanakmmnrizvipxmbjglugytjwanyrdwsrwcdirxsqucitpldvxxdxqntscrkgnczjgctybmqwqarfmucjriikvbczsofhqeszjlxkzpiqqavewapoixafyeeqtkzlqrkzchmczwupypvvrklzhlefrlxkxwwnpgprqdvpbpgchbxynkyuxeborazoyxendvgvackbtsdavczimzclffaxfbndyrqdozzoblqwgvxbyykmzoyguafbbtfbmxgbwhpzthwbdvcdtopudnazngaqbfrnfaqdhidcpbdswgvrunnzapyqvziygcmlcerjmuocxrwvzuowhbvjqubovkmbmapofgzrcnvbhswgokcvnagfwitr");
	std::vector<std::string> words{ "odlrujkkvkszpupcvulw","ybcydvonkzsuapxtpkag","lsxdcyahnlydqkulvexq","bjyqnwsfvhyzqzsowuxy","hzqajnletkwmzoslxeua","zpsjcfbhlllnmcwcswps","cufbbjexexqbaarokple","xakqoivxsulrsrajmpew","nluhkjrninanoovoonpi","auqsviiscfqwcsbqhxbn","fylgaaqztivjiuwkihax","eizsyvcgaxwbmqmoyqwl","hjmrqejmjgaybbnkxrqw","ravvxvksoghodziahqsl","zxrozkiziimqhfqqudwn","xmtghpsrzvrmgnvqwmfh","rvafnouleswibxyptswo","abqiooamagteoqwiieup","ddcomydhbqfbsjzvfplp","ntzojtcgzwiywzpvmzxu","jzxbsanfprdtljwoualy","wxgjptmsilqhwhebtsrt","qprgmhkhdvdopatrawan","paxlaojongkwrxnkdxwn","yljaflsokwccwzxtvjnj","cguqusgkfvsdhnlqdfkc" };
	std::vector<int> expectedOutput{206};
	//std::string output;
	//for (int& i : solution.findSubstring(input, words)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.findSubstring(input, words) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(SearchRange_TEST_1)
{
	Solution solution;
	std::vector<int> input{ 5,7,7,8,8,10 };
	std::vector<int> expectedOutput{ 3,4 };	
	//std::string output;
	//for (int& i : solution.searchRange(input, 8)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.searchRange(input, 8) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(SearchRange_TEST_2)
{
	Solution solution;
	std::vector<int> input{ 5,7,7,8,8,10 };
	std::vector<int> expectedOutput{ 3,4 };
	//std::string output;
	//for (int& i : solution.searchRange(input, 6)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.searchRange(input, 8) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(SearchRange_TEST_3)
{
	Solution solution;
	std::vector<int> input;
	std::vector<int> expectedOutput{ -1,-1 };
	//std::string output;
	//for (int& i : solution.searchRange(input, 0)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.searchRange(input, 0) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(SearchRange_TEST_4)
{
	Solution solution;
	std::vector<int> input{ 5,7,7,8,8,8,8,8,8,8,8,10 };
	std::vector<int> expectedOutput{ 3,10 };
	//std::string output;
	//for (int& i : solution.searchRange(input, 8)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.searchRange(input, 8) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(SearchRange_TEST_5)
{
	Solution solution;
	std::vector<int> input{ 1 };
	std::vector<int> expectedOutput{ 0,0 };
	//std::string output;
	//for (int& i : solution.searchRange(input, 1)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.searchRange(input, 1) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(SearchRange_TEST_6)
{
	Solution solution;
	std::vector<int> input{ 2,2 };
	std::vector<int> expectedOutput{ 0,1 };
	//std::string output;
	//for (int& i : solution.searchRange(input, 2)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.searchRange(input, 2) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(SearchRange_TEST_7)
{
	Solution solution;
	std::vector<int> input{ 1,4 };
	std::vector<int> expectedOutput{ 1,1 };
	//std::string output;
	//for (int& i : solution.searchRange(input, 4)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.searchRange(input, 4) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(SearchRange_TEST_8)
{
	Solution solution;
	std::vector<int> input{ 1,2,3 };
	std::vector<int> expectedOutput{ 0,0 };
	//std::string output;
	//for (int& i : solution.searchRange(input, 1)) {
	//	output += std::to_string(i) + " ";
	//}
	//output = "RESULT : [ " + output + ']';
	//std::cout << output << "\n";
	BOOST_CHECK(solution.searchRange(input, 1) == expectedOutput);
}

BOOST_AUTO_TEST_CASE(SearchInsert_TEST_1)
{
	Solution solution;
	std::vector<int> input{ 1,3,5,6 };
	//std::cout << "RESULT : " << solution.searchInsert(input, 5) << "\n";
	BOOST_CHECK(solution.searchInsert(input, 5) == 2);
}

BOOST_AUTO_TEST_CASE(SearchInsert_TEST_2)
{
	Solution solution;
	std::vector<int> input{ 1,3,5,6 };
	//std::cout << "RESULT : " << solution.searchInsert(input, 2) << "\n";
	BOOST_CHECK(solution.searchInsert(input, 2) == 1);
}

BOOST_AUTO_TEST_CASE(SearchInsert_TEST_3)
{
	Solution solution;
	std::vector<int> input{ 1,3,5,6 };
	//std::cout << "RESULT : " << solution.searchInsert(input, 7) << "\n";
	BOOST_CHECK(solution.searchInsert(input, 7) == 4);
}

BOOST_AUTO_TEST_CASE(SearchInsert_TEST_4)
{
	Solution solution;
	std::vector<int> input{ 1,2,3,4,5,6,7,8,9,20,21,22,23,24,25,26,27,28,29,30 };
	//std::cout << "RESULT : " << solution.searchInsert(input, 10) << "\n";
	BOOST_CHECK(solution.searchInsert(input, 10) == 9);
}

BOOST_AUTO_TEST_CASE(SearchInsert_TEST_5)
{
	Solution solution;
	std::vector<int> input{ 1,2,3,4,5,6,7,8,9,20,21,22,23,24,25,26,27,28,29,30 };
	//std::cout << "RESULT : " << solution.searchInsert(input, 9) << "\n";
	BOOST_CHECK(solution.searchInsert(input, 9) == 8);
}
