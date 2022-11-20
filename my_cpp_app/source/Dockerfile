FROM gcc:latest


COPY . /usr/src/cpp_app

WORKDIR /usr/src/cpp_app

RUN g++ -o Test main.cpp

CMD ["./Test"]