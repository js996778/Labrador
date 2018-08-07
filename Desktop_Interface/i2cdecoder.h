#ifndef I2CDECODER_H
#define I2CDECODER_H

#include <QObject>
#include "isobuffer.h"

namespace i2c
{

enum class transmissionState: uint8_t
{
	idle,
	address,
	data	
};

enum class edge: uint8_t
{
	rising,
	falling,
	held_high,
	held_low
};

class i2cDecoder : public QObject
{
    Q_OBJECT
public:
    explicit i2cDecoder(isoBuffer* sda_in, isoBuffer* scl_in, uint32_t clockRate);
private:
    isoBuffer* sda;
	isoBuffer* scl;
	uint8_t currentSdaValue;
	uint8_t previousSdaValue;
	uint8_t currentSclValue;
	uint8_t previousSclValue;
    uint64_t serialPtr_bit = 0;
	void updateBitValues();
	uint32_t stepSize;
	void setStepSize(uint32_t clockRate);
	void runStateMachine();
    void run(); 
    int serialDistance(isoBuffer* buffer);
	edge edgeDetection(uint8_t current, uint8_t prev);
signals:
public slots:

};

} // Namespace i2c

#endif // UARTSTYLEDECODER_H
