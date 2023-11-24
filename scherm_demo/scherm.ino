int touch_x() {
  TS_Point p = ts.getPoint();
  float x = (p.x - xcorrectie) / xfactor;
  Serial.print("x: ");
  Serial.println(x);
  return x;
}
int touch_y() {
  TS_Point p = ts.getPoint();
  float y = (p.y - ycorrectie) / yfactor;
  Serial.print("y: ");
  Serial.println(y);
  return y;
}