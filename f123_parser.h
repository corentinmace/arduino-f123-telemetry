PacketHeader parseHeader(uint8_t* buffer) {
  PacketHeader header;
  memcpy(&(header.m_packetFormat), buffer, sizeof(uint16_t));
  buffer+=sizeof(uint16_t);

  memcpy(&(header.m_gameYear), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  memcpy(&(header.m_gameMajorVersion), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  memcpy(&(header.m_gameMinorVersion), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  memcpy(&(header.m_packetVersion), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  memcpy(&(header.m_packetId), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  memcpy(&(header.m_sessionUID), buffer, sizeof(uint64_t));
  buffer+=sizeof(uint64_t);

  memcpy(&(header.m_sessionTime), buffer, sizeof(float));
  buffer+=sizeof(float);

  memcpy(&(header.m_frameIdentifier), buffer, sizeof(uint32_t));
  buffer+=sizeof(uint32_t);

  memcpy(&(header.m_overallFrameIdentifier), buffer, sizeof(uint32_t));
  buffer+=sizeof(uint32_t);

  memcpy(&(header.m_playerCarIndex), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  memcpy(&(header.m_secondaryPlayerCarIndex), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  return header;
}

CarTelemetryData parseCarTelemetry(uint8_t* buffer) {
  CarTelemetryData carTelemetry;
  memcpy(&(carTelemetry.m_speed), buffer, sizeof(uint16_t));
  buffer+=sizeof(uint16_t);

  memcpy(&(carTelemetry.m_throttle), buffer, sizeof(float));
  buffer+=sizeof(float);

  memcpy(&(carTelemetry.m_steer), buffer, sizeof(float));
  buffer+=sizeof(float);

  memcpy(&(carTelemetry.m_brake), buffer, sizeof(float));
  buffer+=sizeof(float);

  memcpy(&(carTelemetry.m_clutch), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  memcpy(&(carTelemetry.m_gear), buffer, sizeof(int8_t));
  buffer+=sizeof(int8_t);

  memcpy(&(carTelemetry.m_engineRPM), buffer, sizeof(uint16_t));
  buffer+=sizeof(uint16_t);

  memcpy(&(carTelemetry.m_drs), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  memcpy(&(carTelemetry.m_revLightsPercent), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  memcpy(&(carTelemetry.m_revLightsBitValue), buffer, sizeof(uint16_t));
  buffer+=sizeof(uint16_t);

  memcpy(&(carTelemetry.m_brakesTemperature[4]), buffer, sizeof(uint16_t));
  buffer+=sizeof(uint16_t);

  memcpy(&(carTelemetry.m_tyresSurfaceTemperature[4]), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  memcpy(&(carTelemetry.m_tyresInnerTemperature[4]), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);

  memcpy(&(carTelemetry.m_engineTemperature), buffer, sizeof(uint16_t));
  buffer+=sizeof(uint16_t);

  memcpy(&(carTelemetry.m_tyresPressure[4]), buffer, sizeof(float));
  buffer+=sizeof(float);

  memcpy(&(carTelemetry.m_surfaceType[4]), buffer, sizeof(uint8_t));
  buffer+=sizeof(uint8_t);


  return carTelemetry;
}