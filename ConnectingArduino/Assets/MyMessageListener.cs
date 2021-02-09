using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class MyMessageListener : MonoBehaviour
{
    [SerializeField]
    GameObject plierA;
    [SerializeField]
    GameObject plierB;
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
        Debug.Log("Arrived: " + msg);
        //spinner.transform.Translate(Vector3.forward * Time.deltaTime * float.Parse(msg) * 10);
        //spinner.transform.Rotate(0f, Time.deltaTime * float.Parse(msg) * 10, 0f, Space.World);
        plierA.transform.eulerAngles = new Vector3(0, -Mathf.Log(float.Parse(msg)) * 200, 0);
        plierB.transform.eulerAngles = new Vector3(0, Mathf.Log(float.Parse(msg)) * 200, 0);
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