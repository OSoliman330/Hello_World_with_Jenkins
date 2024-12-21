pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/OSoliman330/Hello_World_with_Jenkins.git'
            }
        }
        stage('Build') {
            steps {
                bat '''
                @echo off
                echo "Building the project..."
                mkdir build
                cd build
                cmake -DCMAKE_BUILD_TYPE=Debug ..
                cmake --build . --config Debug --verbose
                echo "Build completed successfully."
                '''
            }
        }
        stage('Test') {
            steps {
                bat '''
                @echo off
                echo "Testing the project..."
                cd build/bin
                TestMax.exe
                echo "Tests completed successfully."
                '''
            }
        }
        stage('Run') {
            steps {
                bat '''
                @echo off
                echo "Running the project..."
                cd build/bin
                HelloWorld.exe
                echo "Project run successfully."
                '''
            }
        }
    }
}