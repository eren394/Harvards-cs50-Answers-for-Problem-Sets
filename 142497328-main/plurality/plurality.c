#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Maksimum aday sayısı
#define MAX 9

// Aday yapısı (struct)
typedef struct
{
    string name;
    int votes;
}
candidate;

// Aday dizisi
candidate candidates[MAX];

// Aday sayısı değişkeni
int candidate_count;

// Fonksiyon prototipleri
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Geçersiz kullanım kontrolü
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Aday sayısını belirle
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Aday listesini doldur
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Oy verme işlemi
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Geçersiz aday kontrolü
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Kazananı yazdır
    print_winner();
}

// Oyları güncelleme fonksiyonu
bool vote(string name)
{
    // Aday listesinde dolaş
    for (int i = 0; i < candidate_count; i++)
    {
        // Girilen isim aday listesinde var mı kontrol et
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Varsa oy sayısını artır ve true dön
            candidates[i].votes++;
            return true;
        }
    }
    // İsim bulunamazsa false dön
    return false;
}

// Kazananı (veya kazananları) yazdırma fonksiyonu
void print_winner(void)
{
    int max_votes = 0;

    // 1. Adım: En yüksek oy sayısını bul
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // 2. Adım: En yüksek oya sahip olan tüm adayları yazdır
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
