#include "Solution.h"

Solution::Solution()
{

}

Solution::~Solution()
{

}

int Solution::expandAroundCenter(std::string const& s, int left, int right) 
{
	while (left >= 0 && right < s.length() && s[left] == s[right]) {
		//std::cout << left << " :: " << right << std::endl;
		--left;
		++right;
	}
	return (right - left - 1);
}

double Solution::findMedianSortedArrays(std::vector<int> const& nums1, std::vector<int> const& nums2) 
{
	if (nums2.size() < nums1.size()) {
		return findMedianSortedArrays(nums2, nums1);
	}
	int cut1;
	int cut2;
	int n1 = static_cast<int>(nums1.size());
	int n2 = static_cast<int>(nums2.size());
	int low = 0;
	int high = n1;
	while (low <= high) {
		cut1 = (low + high) / 2;
		cut2 = ((n1 + n2 + 1) / 2) - cut1;
		int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
		int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
		int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
		int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
		if (l1 <= r2 && l2 <= r1) {
			if ((n1 + n2) % 2 == 0) {
				return (std::max(l1, l2) + std::min(r1, r2)) / 2.0;
			}
			return std::max(l1, l2);
		}
		else if (l1 > r2) {
			high = cut1 - 1;
		}
		else {
			low = cut1 + 1;
		}
	}
	return 0.0;
}

double Solution::findMedianSortedArraysOld(std::vector<int> const& nums1, std::vector<int> const& nums2) 
{
	double median = 0;
	size_t commonLength = nums1.size() + nums2.size();
	size_t commonHalfLength = commonLength / 2;
	bool isOdd = commonLength % 2;

	if (nums1.empty()) {
		median = isOdd ? nums2[commonHalfLength] :
			(static_cast<double>(nums2[commonHalfLength - 1]) + nums2[commonHalfLength]) / 2;
		return median;
	}

	if (nums2.empty()) {
		median = isOdd ? nums1[commonHalfLength] :
			(static_cast<double>(nums1[commonHalfLength - 1]) + nums1[commonHalfLength]) / 2;
		return median;
	}

	size_t itr1 = nums1.size() - 1;
	size_t itr2 = nums2.size() - 1;

	while (itr1 + itr2 >= commonHalfLength) {
		if (nums1[itr1] > nums2[itr2]) {
			if (!itr1) break;
			itr1 /= 2;
		}
		else {
			if (!itr2) break;
			itr2 /= 2;
		}
	}

	while (itr1 + itr2 <= commonHalfLength) {
		if (nums1[itr1] < nums2[itr2]) {
			median = nums1[itr1];
			itr1 < nums1.size() - 1 ? itr1++ : itr2++;
		}
		else {
			median = nums2[itr2];
			itr2 < nums2.size() - 1 ? itr2++ : itr1++;
		}
	}

	if (!isOdd) {
		if (itr1 > nums1.size() - 1) itr1--;
		if (itr2 > nums2.size() - 1) itr2--;
		while (nums1[itr1] >= median && itr1) itr1--;
		while (nums2[itr2] >= median && itr2) itr2--;
		median = nums1[itr1] > nums2[itr2] ?
			(median + nums1[itr1]) / 2 : (median + nums2[itr2]) / 2;
	}

	return median;
}

std::string Solution::longestPalindrome(std::string s)
{
	if (s.empty())
		return "";

	int start = 0, end = 0;
	for (int i = 0; i < s.length(); ++i) {
		int len1 = expandAroundCenter(s, i, i);
		int len2 = expandAroundCenter(s, i, i + 1);
		int len = len1 > len2 ? len1 : len2;
		if (len > end - start) {
			start = i - ((len - 1) / 2);
			end = i + (len / 2);
			//std::cout << start << " :: " << end << " :: " << len << std::endl;
		}
	}

	return s.substr(start, end - start + 1);
}

std::string Solution::convert(std::string s, int numRows)
{
	if (numRows == 1) return s;

	std::vector<std::string> puzzle(std::min(static_cast<int>(s.size()), numRows));
	std::string result;
	int itr = 0;
	bool direction = false;

	for (char& c : s) {
		puzzle[itr].push_back(c);
		if (itr == 0 || itr == numRows - 1) 
			direction = !direction;
		direction ? itr++ : itr--;
	}

	for (std::string& part : puzzle)
		result.append(part);

	return result;
}

int Solution::reverse(int x) 
{
	try {
		std::string buff = std::to_string(std::abs(x));
		std::reverse(buff.begin(), buff.end());
		return x < 0 ? std::stoi(buff) * -1 : std::stoi(buff);
	} catch (...) {
		return 0;
	}
}

int Solution::myAtoi(std::string s)
{
	if (!s.length()) return 0;
	long long res = 0;
	bool isNegative = false;
	bool signMet = false;
	for (size_t itr = 0; itr < s.length(); itr++) {
		if (res > 2147483648) break;
		if (s[itr] == ' ' && !signMet) continue;
		else if (s[itr] == '-' && !signMet) {
			isNegative = true;
			signMet = true;
		}
		else if (s[itr] == '+' && !signMet) {
			isNegative = false;
			signMet = true;
		}
		else if (s[itr] < '0' || s[itr] > '9') break;
		else {
			signMet = true;
			res = res * 10 + (s[itr] - '0');
		}
	}

	if (!isNegative && res > INT_MAX) res = INT_MAX;
	if (isNegative) {
		res *= -1;
		if (res < INT_MIN) res = INT_MIN;
	}

	return static_cast<int>(res);
}

std::vector<int> Solution::twoSumOLD(std::vector<int>& nums, int target) 
{
	std::vector<int> results;
	int part = 0;
	for (int n = 0; n < nums.size(); n++)
	{
		part = target - nums[n];
		for (int n1 = n + 1; n1 < nums.size(); n1++) {
			if (part == nums[n1]) {
				results.push_back(n);
				results.push_back(n1);
				return results;
			}
		}
	}
	return results;
}

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) 
{
	std::vector<int> output;
	if (nums.empty()) 
		return output;
	std::vector<std::pair<int, int>> sortedNums;
	for (int num = 0; num < nums.size(); num++)
		sortedNums.push_back(std::make_pair(nums[num], num));
	std::sort(sortedNums.begin(), sortedNums.end(), [&](auto& left, auto& right) {
		return left.first < right.first;
		});
	size_t firstNum = 0, secondNum = sortedNums.size() - 1;
	int sum = 0;
	while (firstNum < secondNum) {
		sum = sortedNums[firstNum].first + sortedNums[secondNum].first;
		if (sum < target)
			firstNum++;
		else if (sum > target)
			secondNum--;
		else {
			output.push_back(sortedNums[firstNum].second);
			output.push_back(sortedNums[secondNum].second);
			return output;
		}
	}
	return output;
}

Solution::ListNode* Solution::addTwoNumbers(Solution::ListNode* l1, Solution::ListNode* l2) 
{

	int part = 0;
	int intermedResult = 0;
	int val1, val2;

	Solution::ListNode* head = new Solution::ListNode(intermedResult);
	Solution::ListNode* iterator = head;
	while (NULL != l1 || NULL != l2) {
		val1 = extract(l1);
		val2 = extract(l2);
		intermedResult = val1 + val2 + part;
		if (intermedResult >= 10) {
			intermedResult %= 10;
			part = 1;
		}
		else part = 0;
		iterator->next = new Solution::ListNode(intermedResult);
		iterator = iterator->next;
	}
	if (part) 
		iterator->next = new Solution::ListNode(1);
	iterator = head->next;
	delete head;
	return iterator;
}

int Solution::extract(Solution::ListNode* &node) 
{
	if (nullptr == node) 
		return 0;
	int res = node->val;
	node = node->next;
	return res;
}

int Solution::KMPString(std::string const& pattern, std::string const& input)
{
	size_t patternLength = pattern.length();
	size_t inputLength = input.length();
	size_t i, j;
	int output = 0;
	for (i = 0; i <= patternLength - inputLength; i++) {
		for (j = 0; j < patternLength; j++)
			if (pattern[j] != input[j])
				break;

		if (j == patternLength)
			output++;
	}
	return output;
}

void Solution::backtrackPhoneDigit(std::string const& input, std::string& combination,
	std::map<char, std::string> const& phoneLetters, std::vector<std::string>& output)
{
	if (input.empty()) {
		output.push_back(combination);
		combination.pop_back();
		return;
	}

 	for (auto& ch : phoneLetters.find(input[0])->second) {
		combination += ch;
		backtrackPhoneDigit(input.substr(1), combination, phoneLetters, output);
	}

	combination.pop_back();
}

std::vector<std::vector<int>> Solution::twoSumAuxiliary(std::vector<int>& nums, long long target, size_t start)
{
	std::vector<std::vector<int>> output;
	size_t firstNum = start, secondNum = nums.size() - 1;
	long long sum = 0;
	while (firstNum < secondNum) {
		sum = nums[firstNum] + nums[secondNum];
		if (sum < target || (firstNum > start && nums[firstNum - 1] == nums[firstNum]))
			firstNum++;
		else if (sum > target || (secondNum < nums.size() - 1 && nums[secondNum + 1] == nums[secondNum]))
			secondNum--;
		else {
			output.push_back({ nums[firstNum], nums[secondNum] });
			firstNum++;
			secondNum--;
		}
	}
	return output;
}

std::vector<std::vector<int>> Solution::kSumAuxiliary(std::vector<int>& nums, long long target, size_t start, int k)
{
	std::vector<std::vector<int>> output;
	if (start > nums.size() - 1)
		return output;

	long long middleValue = target / k;
	if (middleValue < nums[start] || middleValue > nums[nums.size() - 1])
		return output;

	if (k == 2)
		return twoSumAuxiliary(nums, target, start);

	for (size_t firstNum = start; firstNum < nums.size() - 1; firstNum++)
		if (firstNum == start || nums[firstNum - 1] != nums[firstNum])
			for (std::vector<int>& subNums : kSumAuxiliary(nums, target - static_cast<long long>(nums[firstNum]), firstNum + 1, k - 1)) {
				output.push_back({ nums[firstNum] });
				output.back().insert(std::end(output.back()), std::begin(subNums), std::end(subNums));
			}

	return output;
}

int Solution::lengthOfLongestSubstring(std::string s) 
{
	if (1 == s.length()) return 1;
	int ascii[128] = { 0 };
	int counter = 0, max = 0, jump = 0;
	for (int i = 0; i < s.length(); i++) {
		if (ascii[static_cast<int>(s[i])] == 0) {
			ascii[static_cast<int>(s[i])] = i + 1;
			counter++;
		}
		else {
			jump = ascii[static_cast<int>(s[i])];
			for (int j = i - counter; j < i; j++)
				ascii[static_cast<int>(s[j])] = 0;
			i = jump;
			ascii[static_cast<int>(s[i])] = i + 1;
			counter = 1;
		}
		if (max < counter) max = counter;
	}
	return max;
}

bool Solution::isPalindrome(int x) 
{
	if (x < 0 || (x % 10 == 0 && x != 0))
		return false;

	int revertedNumber = 0;
	while (x > revertedNumber) {
		revertedNumber = revertedNumber * 10 + x % 10;
		x /= 10;
	}

	return x == revertedNumber || x == revertedNumber / 10;
}

bool Solution::isPalindrome2(int x) 
{
	std::string input(std::to_string(x));
	std::string reversedInput(input);
	std::reverse(reversedInput.begin(), reversedInput.end());
	return(input == reversedInput);
}

int Solution::maxArea(std::vector<int>& height)
{
	int maxArea = 0;
	int start = 0;
	int end = static_cast<int>(height.size() - 1);

	while (end > start) {
		maxArea = std::max(maxArea, std::min(height[start], height[end]) * (end - start));
		if (height[start] < height[end])
			start++;
		else
			end--;
	}

	return maxArea;
}

std::string Solution::intToRoman(int num)
{
	std::string output;

	std::vector<std::pair<int, std::string>> romanMap = {
		{1, "I"}, {4, "IV"}, {5, "V"}, 
		{9, "IX"}, {10, "X"}, 
		{40, "XL"}, {50, "L"}, 
		{90, "XC"}, {100, "C"}, 
		{400, "CD"}, {500, "D"}, 
		{900, "CM"}, {1000, "M"}
	};

	for (auto romanDigit = romanMap.rbegin(); romanDigit != romanMap.rend(); romanDigit++) {
		while (num >= romanDigit->first) {
			num -= romanDigit->first;
			output += romanDigit->second;
		}
	}

	return output;
}

int Solution::romanToInt(std::string s)
{
	int output = 0;

	std::vector<std::pair<int, std::string>> romanMap = {
		{1, "I"}, {4, "IV"}, {5, "V"},
		{9, "IX"}, {10, "X"},
		{40, "XL"}, {50, "L"},
		{90, "XC"}, {100, "C"},
		{400, "CD"}, {500, "D"},
		{900, "CM"}, {1000, "M"}
	};

	size_t itr = 0;
	for (auto romanDigit = romanMap.rbegin(); romanDigit != romanMap.rend(); romanDigit++) {
		while (romanDigit->second == s.substr(itr, romanDigit->second.length())) {
			output += romanDigit->first;
			itr += romanDigit->second.length();
		}
	}

	return output;
}

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs)
{
	if (strs.empty())
		return "";

	size_t min = SIZE_MAX;
	for (std::string& str : strs)
		if (str.length() < min)
			min = str.length();
	
	auto minMaxStr = std::minmax_element(
		strs.begin(), strs.end(),
		[&](std::string& left, std::string& right)
		{
			return left.compare(0, min, right, 0, min) < 0;
		});

	for (min = 0; min < minMaxStr.first->length(); min++)
		if ((*minMaxStr.first)[min] != (*minMaxStr.second)[min])
			break;

	if (min)
		return minMaxStr.first->substr(0, min);
	else
		return "";
}

std::string Solution::longestCommonPrefixWithStructuralBinding(std::vector<std::string>& strs)
{
	if (strs.empty())
		return {};

	const auto N = min_element(
		begin(strs), end(strs),
		[](const auto& L, const auto& R) 
		{
			return L.size() < R.size();
		})->size();

	const auto [iter, jter] = minmax_element(
		begin(strs), end(strs),
		[&](const auto& L, const auto& R) 
		{
			return L.compare(0, N, R, 0, N) < 0;
		});

	const auto [I, J] = mismatch(
		begin(*iter), begin(*iter) + N,
		begin(*jter), begin(*jter) + N);

	const auto len = std::min(
		distance(begin(*iter), I),
		distance(begin(*jter), J));

	return iter->substr(0, len);

}

std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());
	std::vector<std::vector<int>> output;
	std::set<std::vector<int>> triplesSet;
	size_t firstNum, secondNum, thirdNum;
	int sum;

	for (firstNum = 0; firstNum < nums.size() - 2; firstNum++) {
		if (nums[firstNum] > 0) break;

		secondNum = firstNum + 1;
		thirdNum = nums.size() - 1;

		while (secondNum < thirdNum) {
			sum = nums[firstNum] + nums[secondNum] + nums[thirdNum];
			if (sum < 0)
				secondNum++;
			else if (sum > 0)
				thirdNum--;
			else {
				triplesSet.insert({ nums[firstNum], nums[secondNum] , nums[thirdNum] });
				secondNum++;
				thirdNum--;
			}
		}
	}

	for (auto& triple : triplesSet)
		output.push_back(triple);

	return output;
}

int Solution::threeSumClosest(std::vector<int>& nums, int target)
{
	std::sort(nums.begin(), nums.end());
	size_t firstNum, secondNum, thirdNum;
	int sum, closestTarget = 20000, output = 20000;

	for (firstNum = 0; firstNum < nums.size() - 2; firstNum++) {
		secondNum = firstNum + 1;
		thirdNum = nums.size() - 1;

		while (secondNum < thirdNum) {
			sum = nums[firstNum] + nums[secondNum] + nums[thirdNum];

			if (std::abs(sum - target) < closestTarget) {
				output = sum;
				closestTarget = std::abs(sum - target);
			}

			if (sum < target)
				secondNum++;
			else if (sum > target)
				thirdNum--;
			else
				return sum;
		}
	}

	return output;
}

std::vector<std::string> Solution::letterCombinations(std::string digits)
{
	std::vector<std::string> output;
	if (digits.empty()) 
		return output;

	std::string combination;
	std::map<char, std::string> phoneLetters = {
		{'2', "abc"}, {'3', "def"},	{'4', "ghi"}, {'5', "jkl"}, 
		{'6', "mno"},	{'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
	};

	//backtrackPhoneDigit(digits, combination, phoneLetters, output);
	std::function<void(std::string const&, std::string &)> backtracking =
		[phoneLetters, &output, &backtracking](std::string input, std::string& combination) {
		if (input.empty()) {
			output.push_back(combination);
			combination.pop_back();
			return;
		}
		for (auto& ch : phoneLetters.find(input[0])->second) {
			combination += ch;
			backtracking(input.substr(1), combination);
		}
		combination.pop_back();
	};
	backtracking(digits, combination);
	return output;
}

std::vector<std::vector<int>> Solution::fourSum(std::vector<int>& nums, int target)
{
	std::sort(nums.begin(), nums.end());
	return kSumAuxiliary(nums, static_cast<long long>(target), 0, 4);
}

Solution::ListNode* Solution::removeNthFromEnd(Solution::ListNode* head, int n)
{
	Solution::ListNode* iterator = head;
	Solution::ListNode* deleyedIterator = head;
	int index = 0;

	while (nullptr != iterator->next) {
		iterator = iterator->next;

		if (index == n)
			deleyedIterator = deleyedIterator->next;
		else
			index++;
	}

	if (index == n) {
		iterator = deleyedIterator->next;
		if (nullptr != iterator) {
			deleyedIterator->next = iterator->next;
			delete iterator;
		}
		else
			delete deleyedIterator;
	}
	else if (index + 1 == n) {
		iterator = head;
		head = head->next;
		delete iterator;
	}

	return head;
}

bool Solution::isValidParentheses(std::string s)
{
	std::stack<char> parenthesesStack;
	std::map<char, char> parenthesesMap = {
		{')','('}, {']','['}, {'}','{'}
	};
	std::map<char, char>::iterator itr;

	for (char& ch : s) {
		itr = parenthesesMap.find(ch);
		if (itr != parenthesesMap.end())
			if (!parenthesesStack.empty() && itr->second == parenthesesStack.top())
				parenthesesStack.pop();
			else
				return false;
		else
			parenthesesStack.push(ch);
	}

	return parenthesesStack.empty();

}

Solution::ListNode* Solution::mergeTwoLists(Solution::ListNode* list1, Solution::ListNode* list2)
{
	if (nullptr == list1)
		return list2;
	if (nullptr == list2)
		return list1;

	Solution::ListNode* head = nullptr;
	Solution::ListNode* tail = nullptr;

	if (list1->val < list2->val) {
		head = list1;
		list1 = list1->next;
	}
	else {
		head = list2;
		list2 = list2->next;
	}

	tail = head;

	while (nullptr != list1 && nullptr != list2) {
		if (list1->val < list2->val) {
			tail->next = list1;
			tail = tail->next;
			list1 = list1->next;
		}
		else {
			tail->next = list2;
			tail = tail->next;
			list2 = list2->next;
		}
	}

	if (nullptr == list1)
		tail->next = list2;
	if (nullptr == list2)
		tail->next = list1;

	return head;
}

std::vector<std::string> Solution::generateParenthesis(int n)
{
	std::vector<std::string> output;

	if (!n)
		return output;

	std::function<void(int,int,std::string)> backtracking =
		[n, &output, &backtracking](int nLeftParenthesis, int nRightParenthesis, std::string generatedParenthesis) {
		if (n == nLeftParenthesis && n == nRightParenthesis) {
			output.push_back(generatedParenthesis);
			return;
		}
		if (nLeftParenthesis < n)
			backtracking(nLeftParenthesis + 1, nRightParenthesis, generatedParenthesis + '(');
		if (nLeftParenthesis > nRightParenthesis)
			backtracking(nLeftParenthesis, nRightParenthesis + 1, generatedParenthesis + ')');
	};
	backtracking(0, 0, std::string(""));
	///// IN C++23 /////
	//[n, &output](this auto self, int nLeftParenthesis, int nRightParenthesis, std::string generatedParenthesis) {
	//	if (n == nLeftParenthesis && n == nRightParenthesis) {
	//		output.push_back(generatedParenthesis);
	//		return;
	//	}
	//	if (nLeftParenthesis < n)
	//		self(nLeftParenthesis + 1, nRightParenthesis, generatedParenthesis + '(');
	//	if (nLeftParenthesis > nRightParenthesis)
	//		self(nLeftParenthesis, nRightParenthesis + 1, generatedParenthesis + ')');
	//} (0, 0, std::string(""));

	return output;
}

Solution::ListNode* Solution::mergeKLists(std::vector<Solution::ListNode*>& lists)
{
	if (!lists.size())
		return nullptr;

	size_t step = 1;
	while (step < lists.size()) {
		for (size_t iterator = 0; iterator + step < lists.size(); iterator = iterator + (step * 2))
			lists[iterator] = mergeTwoLists(lists[iterator], lists[iterator + step]);
		step *= 2;
	}

	return lists[0];
}

Solution::ListNode* Solution::swapPairs(Solution::ListNode* head)
{
	if (nullptr == head)
		return head;

	std::unique_ptr<Solution::ListNode> headPointer(new Solution::ListNode(0, head));
	Solution::ListNode* beforeTail = headPointer.get(), *tail = head;
	Solution::ListNode* nextPair = nullptr, *swapNode = nullptr;

	while (nullptr != tail && nullptr != tail->next) {
		nextPair = tail->next->next;
		swapNode = tail;

		tail = tail->next;
		swapNode->next = tail->next;
		tail->next = swapNode;

		beforeTail->next = swapNode;
		beforeTail = swapNode;
		tail = nextPair;
	}

	return headPointer->next;
}

Solution::ListNode* Solution::reverseKGroup(Solution::ListNode* head, int k)
{
	if (nullptr == head || k == 1)
		return head;

	std::unique_ptr<Solution::ListNode> headPointer(new Solution::ListNode(0, head));
	Solution::ListNode* prevGroup = headPointer.get();
	Solution::ListNode* nextGroup = nullptr, *kStepPtr = nullptr, 
		*currPtr = nullptr, * prevPtr = nullptr, * tempPtr = nullptr;

	std::function<Solution::ListNode* (Solution::ListNode*, int)> traverseKNodes =
		[](Solution::ListNode* start, int step) {
		while (nullptr != start && step > 0) {
			start = start->next;
			step--;
		}
		return start;
	};

	while (nullptr != (kStepPtr = traverseKNodes(prevGroup, k))) {
		nextGroup = kStepPtr->next;
		currPtr = prevGroup->next;
		prevPtr = nextGroup;
		while (currPtr != nextGroup) {
			tempPtr = currPtr->next;
			currPtr->next = prevPtr;
			prevPtr = currPtr;
			currPtr = tempPtr;
		}

		tempPtr = prevGroup->next;
		prevGroup->next = kStepPtr;
		prevGroup = tempPtr;
	}

	return headPointer->next;
}

int Solution::removeDuplicates(std::vector<int>& nums)
{
	int formedIndx = 0;
	for (int indx = 0; indx < nums.size(); ++indx) {
		if (nums[formedIndx] != nums[indx])
			nums[++formedIndx] = nums[indx];
	}
	return ++formedIndx;
}

int Solution::removeElement(std::vector<int>& nums, int val)
{
	int formedIndex = 0;
	for (int indx = 0; indx < nums.size(); ++indx) {
		if (nums[indx] != val) {
			nums[formedIndex] = nums[indx];
			++formedIndex;
		}
	}
	return formedIndex;
}

int Solution::strStr(std::string haystack, std::string needle)
{
	if (needle.size() > haystack.size())
		return -1;

	size_t sameCount = 0;
	for (size_t itr = 0; itr + needle.size() - 1 - sameCount < haystack.size(); ++itr) {
		if (needle[sameCount] == haystack[itr])
			++sameCount;
		else {
			itr = itr - sameCount;
			sameCount = 0;
		}

		if (sameCount == needle.size())
			return static_cast<int>(itr - sameCount + 1);
	}
	return -1;
}

int Solution::divide(int dividend, int divisor)
{
	long long output = 0, intMax = INT_MAX;
	bool positiveOutput = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);

	if ((divisor == 1 || divisor == -1) && positiveOutput) {
		output = dividend;
		if (output < 0)
			output = ~output + 1;
		output = output > intMax ? intMax : output;
		return static_cast<int>(output);
	}
	else if (divisor == 1 || divisor == -1) {
		output = dividend;
		if (output > 0)
			output = ~output + 1;
		output = output < INT_MIN ? INT_MIN : output;
		return static_cast<int>(output);
	}

	long long absDividend = dividend, absDivisor = divisor;
	if (absDividend < 0)
		absDividend = ~absDividend + 1;
	if (absDivisor < 0 )
		absDivisor = ~absDivisor + 1;
	long long reminder = absDivisor, quotent = 1;

	while (absDividend >= absDivisor) {
		quotent = 1;
		reminder = absDivisor;
		while (absDividend >= reminder) {
			quotent <<= 1;
			reminder <<= 1;
		}
		output += quotent >> 1;
		absDividend -= reminder >> 1;
	}

	if (positiveOutput) {
		output = output > intMax ? intMax : output;
		return static_cast<int>(output);
	}
	else {
		output = output > intMax + 1 ? intMax + 1 : output;
		output = ~output + 1;
		return static_cast<int>(output);
	}
}

std::vector<int> Solution::findSubstring(std::string s, std::vector<std::string>& words) 
{
	std::vector<int> output;
	if (s.empty() || words.empty())
		return output;

	size_t expectedSubstringSize = words[0].size() * words.size();

	if (s.size() < expectedSubstringSize)
		return output;

	std::string buffer;
	std::map<std::string, int> wordsCount, wordsCountBuffer;
	std::map<std::string, int>::iterator wordsCountItr;
	for (std::string& word : words) {
		if (wordsCount.find(word) != wordsCount.end())
			wordsCount[word] += 1;
		else
			wordsCount.insert(std::make_pair(word, 1));
	}

	std::function<void(size_t&)> checkWordsComposition =
		[&s, &buffer, &words, &output, &wordsCountItr,
		&expectedSubstringSize, wordsCount, &wordsCountBuffer](size_t& start) {
		wordsCountBuffer = wordsCount;
		size_t indx = start;
		size_t wordsIndx = 0;
		while (indx < start + expectedSubstringSize) {
			buffer = s.substr(indx, words[0].size());
			wordsCountItr = wordsCountBuffer.find(buffer);
			if (wordsCountItr != wordsCountBuffer.end()) {
				if (wordsCountItr->second > 0) {
					wordsCountItr->second -= 1;
					wordsIndx++;
				}
			}
			else {
				wordsIndx = 0;
				wordsCountBuffer = wordsCount;
			}

			indx += words[0].size();
		}

		if (wordsIndx == words.size()) {
			output.push_back(static_cast<int>(start));
		}
	};

	for (size_t indx = 0; indx <= s.size() - expectedSubstringSize; ++indx)
		checkWordsComposition(indx);

	return output;
}

std::vector<int> Solution::findSubstringOptimizedUnfinished(std::string s, std::vector<std::string>& words)
{
	std::vector<int> output;
	if (s.empty() || words.empty())
		return output;

	size_t expectedSubstringSize = words[0].size() * words.size();

	if (s.size() < expectedSubstringSize)
		return output;

	std::string nextWord, leftWord;
	std::map<std::string, int> wordsCount, wordsFound;
	std::map<std::string, int>::const_iterator constWordItr;
	std::map<std::string, int>::iterator wordItr;
	for (std::string& word : words) {
		if (wordsCount.find(word) != wordsCount.end())
			wordsCount[word] += 1;
		else
			wordsCount.insert(std::make_pair(word, 1));
	}

	std::function<void(size_t&)> checkWordsComposition =
		[&s, &nextWord, &leftWord, &words, &output, &constWordItr, &wordItr,
		&expectedSubstringSize, &wordsCount, &wordsFound](size_t& start) {

		wordsFound.clear();// = wordsCount;
		size_t indx = start;
		size_t wordsIndx = 0;
		bool excessWord = false;
		while (indx <= s.size() - words[0].size()) {
			nextWord = s.substr(indx, words[0].size());
			constWordItr = wordsCount.find(nextWord);
			if (constWordItr != wordsCount.end()) {
				while (indx - start == expectedSubstringSize || excessWord) {
					leftWord = s.substr(start, start + words[0].size());
					start += words[0].size();
					wordsFound[leftWord] -= 1;
					if (wordsFound[leftWord] >= wordsCount[leftWord]) {
						excessWord = false;
					}
					else {
						wordsIndx--;
					}
				}

				wordItr = wordsFound.find(nextWord);
				if (wordItr != wordsFound.end())
					wordsFound[nextWord] += 1;
				else
					wordsFound.insert(std::make_pair(nextWord, 1));

				if (wordsFound[nextWord] <= wordsCount[leftWord])
					wordsIndx++;
				else
					excessWord = true;

				if (wordsIndx == words.size() && !excessWord)
					output.push_back(static_cast<int>(start));
			}
			else {
				wordsIndx = 0;
				wordsFound.clear();
				excessWord = false;
				start = indx + words[0].size();
			}
			indx += words[0].size();
		}

	};

	for (size_t indx = 0; indx <= s.size() - expectedSubstringSize; ++indx)
		checkWordsComposition(indx);

	return output;
}

std::vector<int> Solution::searchRange(std::vector<int>& nums, int target)
{
	std::vector<int> output;
	if (nums.empty()) {
		output = std::vector({ -1, -1 });
		return output;
	}

	size_t first = 0, last = nums.size() - 1, median = nums[first] == target ? first : last;
	while (first <= last) {
		if (nums[median] < target)
			first = median;
		else if (nums[median] > target)
			last = median;
		else {
			if (nums[first] != target)
				first = median;
			if (nums[last] != target)
				last = median;

			while (first && nums[first] == target)
				first--;
			if (nums[first] != target)
				first++;

			while (nums.size() - 1 > last && nums[last] == target)
				last++;
			if (nums[last] != target)
				last--;

			output.push_back(static_cast<int>(first));
			output.push_back(static_cast<int>(last));
			return output;
		}
		if (last - first <= 1)
			break;
		median = (first + last) / 2;
	}

	if (output.empty())
		output = std::vector({ -1, -1 });

	return output;
}

int Solution::searchInsert(std::vector<int>& nums, int target)
{
	int output = 0;
	if (nums.empty())
		return 0;

	size_t first = 0, last = nums.size() - 1, median = nums[first] == target ? first : last;
	while (first <= last) {
		if (nums[median] < target)
			first = median;
		else if (nums[median] > target)
			last = median;
		else {
			return static_cast<int>(median);
		}
		median = (first + last) / 2;
		if (last - first <= 1)
			break;
	}
	while (median < nums.size() && nums[median] < target)
		median++;

	return static_cast<int>(median);
}

bool Solution::isValidSudoku(std::vector<std::vector<char>>& board)
{
	std::vector<std::vector<bool>> rows(9, std::vector(9, false));
	std::vector<std::vector<bool>> columns(9, std::vector(9, false));
	std::vector<std::vector<bool>> squares(9, std::vector(9, false));
	size_t square = 0, number = 0;

	for (size_t row = 0; row < 9; ++row)
		for (size_t column = 0; column < 9; ++column) {
			if (board[row][column] == '.')
				continue;

			number = board[row][column] - '1';
			square = row / 3 + (column / 3) * 3;
			if (rows[row][number] || columns[column][number] || squares[square][number])
				return false;

			rows[row][number] = true;
			columns[column][number] = true;
			squares[square][number] = true;
		}

	return true;
}

bool Solution::isValidSudoku2(std::vector<std::vector<char>>& board)
{
	std::vector<std::set<char>> rows = {
		{}, {}, {},
		{}, {}, {},
		{}, {}, {}
	};
	std::vector<std::set<char>> columns = {
		{}, {}, {},
		{}, {}, {},
		{}, {}, {}
	};
	std::vector<std::vector<std::set<char>>> squares = {
		{ {} , {} , {} },
		{ {} , {} , {} },
		{ {} , {} , {} },
	};

	for (size_t row = 0; row < 9; ++row)
		for (size_t column = 0; column < 9; ++column) {
			if (board[row][column] == '.')
				continue;
			if (rows[row].count(board[row][column]) ||
				columns[column].count(board[row][column]) ||
				squares[row / 3][column / 3].count(board[row][column])) {
				return false;
			}
			rows[row].insert(board[row][column]);
			columns[column].insert(board[row][column]);
			squares[row / 3][column / 3].insert(board[row][column]);
		}

	return true;
}

void Solution::solveSudoku(std::vector<std::vector<char>>& board)
{
	std::vector<std::vector<bool>> rows(9, std::vector(9, true));
	std::vector<std::vector<bool>> columns(9, std::vector(9, true));
	std::vector<std::vector<bool>> squares(9, std::vector(9, true));
	size_t square = 0, number = 0;
	bool solved = false;
	for (size_t row = 0; row < 9; ++row)
		for (size_t column = 0; column < 9; ++column) {
			if (board[row][column] == '.')
				continue;

			number = board[row][column] - '1';
			square = row / 3 + (column / 3) * 3;

			rows[row][number] = false;
			columns[column][number] = false;
			squares[square][number] = false;
		}

	std::function<void(size_t, size_t)> backtracking =
		[&solved, &rows, &columns, &squares, &board, &backtracking](size_t row, size_t column) {
		if (row == 9) {
			solved = true;
			return;
		}
		if (board[row][column] != '.')
			backtracking(row + (column + 1) / 9, (column + 1) % 9);
		else {
			size_t square = row / 3 + (column / 3) * 3;
			for (size_t number = 0; number < 9; ++number) {
				if (rows[row][number] && columns[column][number] && squares[square][number]) {
					rows[row][number] = false;
					columns[column][number] = false;
					squares[square][number] = false;
					board[row][column] = static_cast<char>('1' + number);
					backtracking(row + (column + 1) / 9, (column + 1) % 9);
					if (!solved) {
						rows[row][number] = true;
						columns[column][number] = true;
						squares[square][number] = true;
						board[row][column] = '.';
					}
				}
			}
		}
	};
	backtracking(0, 0);
}

std::string Solution::countAndSay(int n)
{
	int count = 0;
	std::string output("1");
	std::vector<std::pair<char, int>> terms;

	std::function<void(std::string&, std::vector<std::pair<char, int>>&)> stringToTerm =
		[&count](std::string& stringToTranslate, std::vector<std::pair<char, int>>& terms) {
		terms.clear();
		for (size_t indx = 0; indx < stringToTranslate.size(); ++indx) {
			++count;
			if (indx == stringToTranslate.size() - 1 || stringToTranslate[indx] != stringToTranslate[indx + 1]) {
				terms.push_back(std::make_pair(stringToTranslate[indx], count));
				count = 0;
			}
		}

		count = 0;
		stringToTranslate = "";
		for (auto& term : terms)
			stringToTranslate += std::to_string(term.second) + term.first;
	};

	for (size_t indx = 0; indx < n - 1; ++indx)
		stringToTerm(output, terms);

	return output;
}

std::vector<std::vector<int>> Solution::combinationSum(std::vector<int>& candidates, int target)
{
	std::vector<std::vector<int>> output;

	std::function<void(size_t, std::vector<int>, int)> backtracking =
		[candidates, target, &output, &backtracking](size_t indx, std::vector<int> usedCandidates, int totalSum) {
		if (totalSum == target) {
			output.push_back(usedCandidates);
			return;
		}

		if (indx > candidates.size() - 1 || totalSum > target)
			return;

		usedCandidates.push_back(candidates[indx]);
		backtracking(indx, usedCandidates, totalSum + candidates[indx]);
		usedCandidates.pop_back();
		backtracking(indx + 1, usedCandidates, totalSum);
	};
	backtracking(0, std::vector<int>(), 0);

	return output;
}

std::vector<std::vector<int>> Solution::combinationSum2(std::vector<int>& candidates, int target)
{
	std::vector<std::vector<int>> output;
	if (candidates.empty())
		return output;
	std::sort(std::begin(candidates), std::end(candidates));

	std::function<void(size_t, std::vector<int>, int)> backtracking =
		[candidates, target, &output, &backtracking](size_t indx, std::vector<int> usedCandidates, int totalSum) {

		if (totalSum == target) {
			output.push_back(usedCandidates);
			return;
		}

		for (size_t nextIndx = indx; nextIndx < candidates.size(); ++nextIndx) {
			if (nextIndx > indx && candidates[nextIndx] == candidates[nextIndx - 1])
				continue;
			if (totalSum + candidates[nextIndx] > target)
				return;
			usedCandidates.push_back(candidates[nextIndx]);
			backtracking(nextIndx + 1, usedCandidates, totalSum + candidates[nextIndx]);
			usedCandidates.pop_back();
		}
	};
	backtracking(0, std::vector<int>(), 0);

	return output;
}

int Solution::firstMissingPositive(std::vector<int>& nums)
{
	for (size_t indx = 0; indx < nums.size(); ++indx)
		while (nums[indx] > 0 && nums[indx] <= nums.size() && nums[indx] != nums[nums[indx] - 1])
			std::swap(nums[indx], nums[nums[indx] - 1]);

	for (size_t indx = 0; indx < nums.size(); ++indx)
		if (nums[indx] != indx + 1)
			return static_cast<int>(indx + 1);

	return static_cast<int>(nums.size() + 1);
}

int Solution::trap(std::vector<int>& height)
{
	int output = 0;
	if (height.empty())
		return output;

	size_t indxLeft = 0;
	size_t indxRight = height.size() - 1;
	int maxLeftBarrier = height[indxLeft];
	int maxRightBarrier = height[indxRight];

	while (indxLeft < indxRight) {
		if (maxLeftBarrier < maxRightBarrier) {
			++indxLeft;
			maxLeftBarrier = std::max(maxLeftBarrier, height[indxLeft]);
			output += maxLeftBarrier - height[indxLeft];
		}
		else {
			--indxRight;
			maxRightBarrier = std::max(maxRightBarrier, height[indxRight]);
			output += maxRightBarrier - height[indxRight];
		}
	}

	return output;
}

std::string Solution::multiply(std::string num1, std::string num2)
{
	if (num1 == "0" || num2 == "0")
		return "0";

	std::string output(num1.size() + num2.size(), '0');
	std::reverse(num1.begin(), num1.end());
	std::reverse(num2.begin(), num2.end());
	int mult = 0;

	for (size_t digitIndx1 = 0; digitIndx1 < num1.size(); ++digitIndx1)
		for (size_t digitIndx2 = 0; digitIndx2 < num2.size(); ++digitIndx2) {
			mult = (num1[digitIndx1] - '0') * (num2[digitIndx2] - '0') + (output[digitIndx1 + digitIndx2] - '0');
			output[digitIndx1 + digitIndx2] = mult % 10 + '0';
			output[digitIndx1 + digitIndx2 + 1] += mult / 10;
		}

	while (output.back() == '0')
		output.pop_back();

	std::reverse(output.begin(), output.end());
	return output;
}
