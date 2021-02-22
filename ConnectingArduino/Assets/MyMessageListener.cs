using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class MyMessageListener : MonoBehaviour
{
    [SerializeField]
    GameObject plierA;
    [SerializeField]
    GameObject plierB;
    float initialPosition = 0;
    Vector3 initialRotation;


    // Use this for initialization
    void Start()
    {
        
    }
    // Update is called once per frame
    void Update()
    {
    }
    // Invoked when a line of data is received from the serial device.
    void OnMessageArrived(string msg)
    {
        float servoPosition = float.Parse(msg);

        Debug.Log(servoPosition);
        //spinner.transform.Translate(Vector3.forward * Time.deltaTime * float.Parse(msg) * 10);
        //spinner.transform.Rotate(0f, Time.deltaTime * float.Parse(msg) * 10, 0f, Space.World);
        //if (initialPosition == 0)
        //{
        //    initialPosition = servoPosition;
        //    initialRotation = new Vector3(0, -Mathf.Log(initialPosition) * 200, 0);
        //    plierA.transform.eulerAngles = initialRotation;
        //    plierB.transform.eulerAngles = initialRotation * (1, -1, 1);
        //}
        //else
        //{

        //}
        //jitters a lot
        //plierA.transform.eulerAngles = new Vector3(0, -Mathf.Log(float.Parse(msg)) * 200, 0);
        //plierB.transform.eulerAngles = new Vector3(0, Mathf.Log(float.Parse(msg)) * 200, 0);

        plierA.transform.eulerAngles = new Vector3(0, -Mathf.Floor(servoPosition / 100) * 3, 0);
        plierB.transform.eulerAngles = new Vector3(0, Mathf.Floor(servoPosition / 100) * 3, 0);


        //spinner.transform.eulerAngles = new Vector3(0f, Time.deltaTime * float.Parse(msg), 0f);

    }
    // Invoked when a connect/disconnect event occurs. The parameter 'success'
    // will be 'true' upon connection, and 'false' upon disconnection or
    // failure to connect.
    void OnConnectionEvent(bool success)
    {
        Debug.Log(success ? "Device connected" : "Device disconnected");
    }
}