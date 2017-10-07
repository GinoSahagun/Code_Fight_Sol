

//Definition for binary tree:
template<typename T>
struct Tree {
	Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
	T value;
	Tree *left;
	Tree *right;

	void add(int val, Tree *&tree)
	{
		if (tree == nullptr)
		{
			tree = new Tree<T>(val);
		}
		else {
			if (tree->left == nullptr)
			{
				add(val, tree->left);
			}
			else
			{
				add(val, tree->right);
			}
		}
	}

};
bool wrapHasPathWithGivenSum(Tree<int> * t, int s, int sum) {

	if (t == nullptr)
	{
		if (s == 0 && sum == 0)
			return true;
		return false;

	}
	sum += t->value;
	if (t->left == nullptr && t->right == nullptr)
	{
		if (sum == s)
		{
			return true;
		}
	}
	return wrapHasPathWithGivenSum(t->left, s, sum) || wrapHasPathWithGivenSum(t->right, s, sum);

}

bool hasPathWithGivenSum(Tree<int> * t, int s) {

	return wrapHasPathWithGivenSum(t, s, 0);

}