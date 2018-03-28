String inputLine;
float value;
boolean dataIn;
color col;

void setup(){
  colorMode(HSB);
  col=color(255);
  size(200,100);
  inputLine="";
}

void draw(){
  background(0);
  fill(255);
  text("input :"+inputLine,50,20,100,20);

  if(dataIn){
    col=color(random(255),random(255),255);
    dataIn=false;
  }
  
  fill(col);
  text(Float.toString(value), 50,40, 150,20);
}

void keyPressed(){
  String tmp=inputLine;

  try{
    tmp+=key;
    value=Float.parseFloat(tmp);
    inputLine=tmp;
  }
  catch(NumberFormatException e){
    // 数値に変換できない文字
    // Enterを例外で受けるのがJava的にいいのかどうかよく知らない
    if(key==ENTER){
      inputLine="";
      dataIn=true;
    }
  }
}