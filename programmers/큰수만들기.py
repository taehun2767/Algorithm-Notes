def solution(number, k):
    stk = []
    for i in number:
        while stk and k > 0 and stk[-1] < i:
            k -= 1
            stk.pop()
        stk.append(i)
    return "".join(stk[:len(stk)-k])
