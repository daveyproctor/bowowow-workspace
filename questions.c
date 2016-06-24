int hash(const char* word)
{
 return (toupper(word[0]) - 'A');
}
While simple (and thus fast to compute), this hash function isn't necessarily the best. Critique this 
hash function, identifying and explaining a downside. 