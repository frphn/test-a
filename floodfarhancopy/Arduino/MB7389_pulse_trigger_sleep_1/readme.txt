The sleep mode has a 3mA consumption due to the Maxbotix being on all
the time. We need a switch to keep current down. To achieve this we use
a N-Channel Logic Level FET as 'low-side' switch to control the power
for the sensor. The current will flow only when the control signal is high. Or we can use our switch as in NIST design.