def solution(phone_book):
    phone_book.sort()

    for i in range(len(phone_book)-1):
        # 접두어가 되기 위한 조건
        if len(phone_book[i]) < len(phone_book[i+1]):
            if phone_book[i] == phone_book[i+1][0:len(phone_book[i])]:
                return False

    return True


phone_book = ["119", "97674223", "1195524421"]

phone_book.sort()

print(solution(["123", "456", "789"]))


