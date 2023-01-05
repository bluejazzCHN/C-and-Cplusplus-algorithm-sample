
#include <iostream>

using namespace std;

class MedicalRecordNumber
{
public:
    MedicalRecordNumber() = default;
    explicit MedicalRecordNumber(uint64_t mrn) : mMRN{mrn} {}

    bool operator==(const MedicalRecordNumber &other) const
    {
        return other.mMRN == mMRN;
    };

    // operator== 的重载
    friend bool operator==(const MedicalRecordNumber &rec, const uint64_t &num)
    {
        return rec.mMRN == num;
    }
    // operator != 重载
    bool operator!=(const MedicalRecordNumber &other) const
    {
        return !(other == *this);
    }

private:
    uint64_t mMRN;
};

int main(int argc, char const *argv[])
{
    MedicalRecordNumber mrn0{};
    MedicalRecordNumber mrn1{3};

    // bool operator==(const MedicalRecordNumber &other)调用
    const bool sameMRN = mrn0 == mrn1;
    const bool notSameMRN = mrn0 != mrn1;
    cout << sameMRN << "|" << notSameMRN << endl; // console： 0|1

    // friend bool operator==(const MedicalRecordNumber& rec,const uint64_t& num)调用
    const bool sameMRNNum = mrn1 == 3.0;
    cout << sameMRNNum << endl; // cosole：1
    return 0;
}
