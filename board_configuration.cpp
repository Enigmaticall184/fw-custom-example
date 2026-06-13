#include "pch.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::B7;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::Unassigned;
}


// board-specific configuration setup
static void customBoardDefaultConfiguration() {

	//stepper pins
	engineConfiguration->idle.stepperDirectionPin = Gpio::D13;
	engineConfiguration->idle.stepperStepPin = Gpio::D15;
	engineConfiguration->stepperEnablePin = Gpio::D14;
	engineConfiguration->idleStepperReactionTime = 10;
	engineConfiguration->idleStepperTotalSteps = 150;
    
	//Injection pins
	engineConfiguration->injectionPins[0] = Gpio::D8;
	engineConfiguration->injectionPins[1] = Gpio::B15;
	engineConfiguration->injectionPins[2] = Gpio::B14;
	engineConfiguration->injectionPins[3] = Gpio::B13;

	//Ignition pins
	engineConfiguration->ignitionPins[0] = Gpio::E15;
	engineConfiguration->ignitionPins[1] = Gpio::E14;
	engineConfiguration->ignitionPins[2] = Gpio::D12;
	engineConfiguration->ignitionPins[3] = Gpio::E5;

	//Trigger pins
    engineConfiguration->triggerInputPins[0] = Gpio::D3; //crank	
	engineConfiguration->triggerInputPins[1] = Gpio::D4; //cam

	
	// adc input pins
	engineConfiguration->vbattAdcChannel = EFI_ADC_2;
	engineConfiguration->map.sensor.hwChannel = EFI_ADC_0;
	engineConfiguration->clt.adcChannel = EFI_ADC_4;
	engineConfiguration->iat.adcChannel = EFI_ADC_5;
	engineConfiguration->tps1_1AdcChannel = EFI_ADC_3;
	engineConfiguration->afr.hwChannel = EFI_ADC_1;

	//inputs and outputs
	engineConfiguration->acSwitch = Gpio::B0;
	engineConfiguration->acRelayPin = Gpio::C7;
	engineConfiguration->fuelPumpPin = Gpio::C8;	
	engineConfiguration->idle.solenoidPin = Gpio::D9;
	engineConfiguration->fanPin = Gpio::A15;	
	engineConfiguration->mainRelayPin = Gpio::E8;
	engineConfiguration->tachOutputPin = Gpio::C9;
	engineConfiguration->vehicleSpeedSensorInputPin = Gpio::D7;

	engineConfiguration->clutchDownPin = Gpio::E12;
	engineConfiguration->clutchDownPinMode = PI_INVERTED_PULLUP;

    // 470 high side/910 low side = 1.56 ratio divider
    engineConfiguration->analogInputDividerCoefficient = 1.516f;

    // 6.34k high side/ 1k low side
    engineConfiguration->vbattDividerCoeff = 7.43;

//	engineConfiguration->adcVcc = 3.3f;

	engineConfiguration->clt.config.bias_resistor = 2400;
	engineConfiguration->iat.config.bias_resistor = 2400;

	engineConfiguration->binarySerialTxPin = Gpio::B10;
	engineConfiguration->binarySerialRxPin = Gpio::B11;

	engineConfiguration->canTxPin = Gpio::Unassigned;
	engineConfiguration->canRxPin = Gpio::Unassigned;
}

	

void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
