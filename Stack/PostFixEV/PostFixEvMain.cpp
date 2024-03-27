

int main() {
    string postfix;
    cout << "Enter the postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
